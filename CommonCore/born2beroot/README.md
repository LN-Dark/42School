Guide -> https://github.com/gemartin99/Born2beroot-Tutorial

Debian ISO -> https://cdimage.debian.org/mirror/cdimage/archive/10.10.0/amd64/iso-cd/debian-10.10.0-amd64-netinst.iso


# Comparação entre Rocky Linux e Debian

## Rocky Linux
- **Base:** 
  - Baseado no Red Hat Enterprise Linux (RHEL), focado em fornecer uma alternativa gratuita e de código aberto para ambientes empresariais.
- **Gerenciamento de Pacotes:** 
  - Usa `yum` ou `dnf` para gerenciamento de pacotes, com pacotes no formato RPM.
- **Público-alvo:** 
  - Voltado principalmente para usuários empresariais e servidores que buscam robustez e confiabilidade.
- **Suporte:** 
  - Suportado pela comunidade e por organizações que buscam uma alternativa ao CentOS.
- **Software:** 
  - Focado em software empresarial e estável disponível nos repositórios do RHEL.

---

## Debian
- **Base:** 
  - Um projeto comunitário que visa ser uma distribuição universal, conhecida por sua estabilidade e liberdade de software.
- **Gerenciamento de Pacotes:** 
  - Usa `apt` para gerenciamento de pacotes, com pacotes no formato DEB.
- **Público-alvo:** 
  - Abrange uma ampla gama de usuários, desde entusiastas até servidores e ambientes de produção.
- **Suporte:** 
  - Tem uma comunidade muito ativa e é conhecido por seu forte compromisso com a liberdade de software.
- **Software:** 
  - Oferece uma vasta gama de pacotes, incluindo opções de software livre e não livre, com foco em inclusão e diversidade.

---

# Configurações de Segurança e Ferramentas

## secure_path
- **Descrição:** Especifica um caminho seguro onde o `sudo` deve procurar por executáveis.
- **Conteúdo:** Lista de diretórios, incluindo:
  - `/usr/local/sbin`: Binários de administração local.
  - `/usr/local/bin`: Binários de aplicativos locais.
  - `/usr/sbin`: Binários de administração do sistema.
  - `/usr/bin`: Binários padrão do sistema.
  - `/sbin`: Binários essenciais do sistema.
  - `/bin`: Binários essenciais.
  - `/snap/bin`: Binários instalados via Snap.

## AppArmor
- **Descrição:** Sistema de controle de acesso baseado em políticas para Linux.
- **Função:** Protege o sistema operacional e os aplicativos de comportamentos indesejados ou maliciosos, restringindo permissões e acesso a arquivos e recursos do sistema.

## LVM (Logical Volume Manager)
- **Descrição:** Ferramenta de gerenciamento de volumes lógicos em sistemas Linux.
- **Benefícios:** Permite gerenciar de forma flexível a alocação de espaço em disco, facilitando a criação, redimensionamento e gerenciamento de volumes de armazenamento.

## UFW (Uncomplicated Firewall)
- **Descrição:** Ferramenta de gerenciamento de firewall que facilita a configuração de regras de iptables em sistemas Linux.
- **Popularidade:** Especialmente popular em distribuições baseadas em Debian e Ubuntu por sua simplicidade.

---

# Gerenciamento de Pacotes: `apt` vs. `aptitude`

| **Aspecto**        | **apt**                                           | **aptitude**                                         |
|--------------------|--------------------------------------------------|-----------------------------------------------------|
| **Interface**      | Mais amigável, saída mais limpa                  | Mais técnica, voltada para usuários avançados       |
| **Funcionalidades**| Resolve dependências de forma eficaz              | Algoritmo avançado, sugere soluções para conflitos  |
| **Histórico**      | Não mantém histórico, a menos que redirecione     | Mantém histórico de comandos, útil para desfazer    |
| **Comandos**       | Ex.: `apt install <pacote>`                      | Ex.: similar, mas com mais opções de interação      |
| **Sugestões**      | Concentra-se em pacotes disponíveis               | Sugere pacotes alternativos ou versões diferentes    |

---

# Instruções de Configuração

Para criar um grupo, use o seguinte comando:  
`sudo groupadd (grupo)`

Para verificar os grupos existentes:  
`getent group`

Para listar todos os usuários:  
`cut -d: -f1 /etc/passwd`

Para criar um novo usuário e adicioná-lo a um grupo:  
`sudo adduser (user) (grupo)`

Para permitir a porta 4242:  
`sudo ufw allow 4242`

Para apagar uma porta:  
`sudo ufw status numbered`  
`sudo ufw delete (porta)`

Para verificar o status do SSH:  
`sudo service ssh status`

Para mudar o hostname:  
`sudo nano /etc/hostname`

Para mostrar as partições:  
`lsblk`

Para editar o crontab do root:  
`sudo crontab -u root -e`



# Script de Monitoramento

Este script coleta e exibe informações sobre o sistema, incluindo arquitetura, uso de CPU, memória, disco, conexões de rede e muito mais.

## Código do Script

```bash
#!/bin/bash

# ARCH
arch=$(uname -a)

# uname -a: Este comando retorna informações detalhadas sobre o sistema, incluindo o nome do kernel, a versão, a arquitetura e mais. O resultado é armazenado na variável arch.


# CPU PHYSICAL
cpuf=$(grep "physical id" /proc/cpuinfo | wc -l)

# CPU VIRTUAL
cpuv=$(grep "processor" /proc/cpuinfo | wc -l)

# /proc/cpuinfo: Este arquivo contém informações sobre a CPU.
# grep "physical id": Conta quantos IDs físicos de CPU existem, que representa CPUs físicas.
# grep "processor": Conta quantos processadores lógicos (ou virtuais) estão presentes.

# RAM
ram_total=$(free --mega | awk '$1 == "Mem:" {print $2}')
ram_use=$(free --mega | awk '$1 == "Mem:" {print $3}')
ram_percent=$(free --mega | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')

# free --mega: Mostra informações sobre o uso de memória em megabytes.
# $1 == "Mem:": Verifica se a linha corresponde à memória total.
# print $2: Retorna a quantidade total de RAM.
# print $3: Retorna a quantidade de RAM em uso.
# Cálculo de porcentagem: Usa a fórmula para calcular a porcentagem de RAM em uso

# DISK
disk_total=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_t += $2} END {printf ("%.1fGb\n"), disk_t/1024}')
disk_use=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} END {print disk_u}')
disk_percent=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} {disk_t+= $2} END {printf("%d"), disk_u/disk_t*100}')

# df -m: Mostra informações sobre o uso de disco em megabytes.
# grep "/dev/": Filtra as linhas que contêm dispositivos de disco.
# grep -v "/boot": Exclui a partição /boot.
# Cálculo de total e uso: Acumula os valores de uso e total para calcular a porcentagem.

# CPU LOAD
cpul=$(vmstat 1 2 | tail -1 | awk '{printf $15}')
cpu_op=$(expr 100 - $cpul)
cpu_fin=$(printf "%.1f" $cpu_op)

# vmstat 1 2: Coleta informações sobre o sistema, incluindo a carga da CPU. A primeira execução é descartada.
# $15: O valor na coluna 15 corresponde ao tempo ocioso da CPU.
# 100 - $cpul: Calcula a carga da CPU subtraindo o tempo ocioso de 100%.

# LAST BOOT
lb=$(who -b | awk '$1 == "system" {print $3 " " $4}')

# who -b: Mostra a data e a hora do último boot do sistema. O comando awk filtra a saída para obter somente a data e hora.

# LVM USE
lvmu=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)

# lsblk: Lista os dispositivos de bloco.
# Verifica se existe alguma entrada relacionada ao LVM e armazena "yes" ou "no" na variável lvmu.

# TCP CONNECTIONS
tcpc=$(ss -ta | grep ESTAB | wc -l)

# ss -ta: Mostra informações sobre conexões TCP.
# grep ESTAB: Filtra para contar apenas as conexões estabelecidas.

# USER LOG
ulog=$(users | wc -w)

# users: Lista os usuários atualmente logados.
# wc -w: Conta o número de palavras, que corresponde ao número de usuários.

# NETWORK
ip=$(hostname -I)
mac=$(ip link | grep "link/ether" | awk '{print $2}')

# hostname -I: Retorna o endereço IP da máquina.
# ip link: Lista informações sobre interfaces de rede.
# grep "link/ether": Filtra a linha que contém o endereço MAC.

# SUDO
cmnd=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

# journalctl: Visualiza logs do sistema.
# Filtra os logs relacionados a comandos executados com sudo e conta quantos foram executados.

wall "	Architecture: $arch
	CPU physical: $cpuf
	vCPU: $cpuv
	Memory Usage: $ram_use/${ram_total}MB ($ram_percent%)
	Disk Usage: $disk_use/${disk_total} ($disk_percent%)
	CPU load: $cpu_fin%
	Last boot: $lb
	LVM use: $lvmu
	Connections TCP: $tcpc ESTABLISHED
	User log: $ulog
	Network: IP $ip ($mac)
	Sudo: $cmnd cmd"

# wall: Envia uma mensagem para todos os usuários logados. As informações coletadas são formatadas e exibidas.



