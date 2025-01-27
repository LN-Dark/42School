#!/bin/bash

# Diretório do projeto
PROJECT_DIR="$1"

# Verifica se o diretório foi passado como argumento
if [ -z "$PROJECT_DIR" ]; then
    echo "Uso: $0 <diretório_do_projeto>"
    exit 1
fi

# Verifica se o diretório existe
if [ ! -d "$PROJECT_DIR" ]; then
    echo "Erro: Diretório '$PROJECT_DIR' não encontrado."
    exit 1
fi

# Função para verificar e corrigir normas com a norminette
check_and_fix_norminette() {
    echo "Verificando normas com a norminette..."
    local files=$(find "$PROJECT_DIR" -name "*.c" -o -name "*.h")
    
    for file in $files; do
        echo "Verificando $file"
        local output=$(norminette "$file")
        echo "$output"
        
        # Tenta corrigir automaticamente problemas comuns
        # (Exemplo: remover espaços em branco extras no final de cada linha)
        # Nota: A norminette não suporta correção automática, então precisamos fazer manualmente
        sed -i 's/[ \t]*$//' "$file" # Remove espaços em branco extras no final de cada linha

        # Adicione outras correções automáticas conforme necessário
        # Por exemplo, para ajustar a indentação, você pode usar outros comandos sed ou ferramentas específicas
        
        # Verifique se há funções longas e notifique o usuário
        while read -r line; do
            if [[ $line == *"function"* ]]; then
                function_lines=0
            fi
            function_lines=$((function_lines + 1))
            if [[ $function_lines -gt 25 ]]; then
                echo "A função no arquivo $file tem mais de 25 linhas. Precisará ser dividida manualmente."
                break
            fi
        done < "$file"
    done
}

# Função para substituir quatro espaços por uma tabulação em um arquivo
replace_spaces_with_tabs() {
    local file="$1"
    echo "Processando $file"
    sed -i 's/    /\t/g' "$file"
}

# Função para compilar e executar testes (ajuste conforme necessário)
run_tests() {
    echo "Compilando projeto..."
    make -C "$PROJECT_DIR"
    if [ $? -eq 0 ]; then
        echo "Compilação bem-sucedida."
        # Executa testes (ajuste conforme necessário)
        EXECUTABLE="$PROJECT_DIR/minishell"
        if [ -f "$EXECUTABLE" ]; then
            echo "Executando testes..."
            "$EXECUTABLE"
        else
            echo "Erro: Executável '$EXECUTABLE' não encontrado."
        fi
    else
        echo "Erro na compilação."
    fi
}

# Função para verificar se arquivos obrigatórios estão presentes
check_required_files() {
    REQUIRED_FILES=("Makefile" "main.c" "project.h")

    for file in "${REQUIRED_FILES[@]}"; do
        if [ ! -f "$PROJECT_DIR/$file" ]; then
            echo "Erro: Arquivo obrigatório '$file' não encontrado."
        fi
    done
}

# Função principal
main() {
    check_required_files
    check_and_fix_norminette
    run_tests

    # Encontra todos os arquivos no diretório e subdiretórios
    local files=$(find "$PROJECT_DIR" -type f)

    # Substitui quatro espaços por uma tabulação em cada arquivo encontrado
    for file in $files; do
        replace_spaces_with_tabs "$file"
    done

    echo "Substituição concluída!"
}

# Executa a função principal
main
