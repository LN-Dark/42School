# Setup Guide and Distribution Comparison

This repository contains instructions for setting up a VM, a comparison between Rocky Linux and Debian, security configurations, package management, and a monitoring script.

## Creating the VM

When following the guide, create the VM with **8GB** instead of **12GB** as mentioned; this way, the partitions will have the correct size shown in the subject screenshot, avoiding issues.

- **Guide:** [Born2beroot-Tutorial](https://github.com/gemartin99/Born2beroot-Tutorial)
- **Debian ISO:** [Debian 10.10.0 Netinst](https://cdimage.debian.org/mirror/cdimage/archive/10.10.0/amd64/iso-cd/debian-10.10.0-amd64-netinst.iso)

---

## Comparison between Rocky Linux and Debian

### Rocky Linux
- **Base:** Based on Red Hat Enterprise Linux (RHEL), focused on providing a free and open-source alternative for enterprise environments.
- **Package Management:** Uses `yum` or `dnf` for package management, with packages in RPM format.
- **Target Audience:** Primarily aimed at enterprise users and servers seeking robustness and reliability.
- **Support:** Supported by the community and organizations seeking an alternative to CentOS.
- **Software:** Focused on enterprise software and stable versions available in RHEL repositories.

### Debian
- **Base:** A community project aimed at being a universal distribution, known for its stability and software freedom.
- **Package Management:** Uses `apt` for package management, with packages in DEB format.
- **Target Audience:** Covers a wide range of users, from enthusiasts to servers and production environments.
- **Support:** Has a very active community, known for its strong commitment to software freedom.
- **Software:** Offers a vast range of packages, including both free and non-free software options.

---

## Security Configurations and Tools

### secure_path
- **Description:** Specifies a secure path where `sudo` should look for executables.
- **Content:** List of directories such as `/usr/local/sbin`, `/usr/local/bin`, `/usr/sbin`, etc.

### AppArmor
- **Description:** Policy-based access control system for Linux.
- **Function:** Protects the operating system and applications from unwanted behaviors.

### LVM (Logical Volume Manager)
- **Description:** Tool for managing logical volumes in Linux systems.
- **Benefits:** Allows flexible disk space allocation management.

### UFW (Uncomplicated Firewall)
- **Description:** Firewall management tool that simplifies the configuration of iptables rules.
- **Popularity:** Especially popular in Debian and Ubuntu-based distributions for its simplicity.

---

## Package Management: `apt` vs. `aptitude`

| **Aspect**        | **apt**                                           | **aptitude**                                         |
|--------------------|--------------------------------------------------|-----------------------------------------------------|
| **Interface**      | More user-friendly, cleaner output               | More technical, aimed at advanced users             |
| **Features**       | Effectively resolves dependencies                 | Advanced algorithm, suggests solutions for conflicts |
| **History**        | Does not maintain history unless redirected      | Maintains command history, useful for undoing       |
| **Commands**       | Ex.: `apt install <package>`                     | Ex.: similar, but with more interaction options      |
| **Suggestions**    | Focuses on available packages                     | Suggests alternative packages or different versions  |

---

## Configuration Instructions

- **Create a group:** `sudo groupadd (group)`
- **Check existing groups:** `getent group`
- **List all users:** `cut -d: -f1 /etc/passwd`
- **Create a new user and add to a group:** `sudo adduser (user) (group)`
- **Allow port 4242:** `sudo ufw allow 4242`
- **Remove a port:** `sudo ufw status numbered` and `sudo ufw delete (port)`
- **Check SSH status:** `sudo service ssh status`
- **Change the hostname:** `sudo nano /etc/hostname`
- **Show partitions:** `lsblk`
- **Edit root's crontab:** `sudo crontab -u root -e`
- **Check SUDO status:** `sudo -l`
- **Connect via SSH:** `ssh user@127.0.0.1 -p (port)`
- **Crontab command:** `@reboot /path/to/script.sh &`
- **Send files:** `scp -P (port) '/path/to/file.sh' test@127.0.0.1:/destination/`

---

## Monitoring Script

This script collects and displays information about the system, including architecture, CPU usage, memory, disk, and network connections.

### Script Code

```bash
#!/bin/bash

while true; do
# ARCH
arch=$(uname -a)

# uname -a: This command returns detailed information about the system, including the kernel name, version, architecture, and more. The result is stored in the variable arch.

# CPU PHYSICAL
cpuf=$(grep "physical id" /proc/cpuinfo | wc -l)

# CPU VIRTUAL
cpuv=$(grep "processor" /proc/cpuinfo | wc -l)

# /proc/cpuinfo: This file contains information about the CPU.
# grep "physical id": Counts how many physical CPU IDs exist, which represents physical CPUs.
# grep "processor": Counts how many logical (or virtual) processors are present.

# RAM
ram_total=$(free --mega | awk '$1 == "Mem:" {print $2}')
ram_use=$(free --mega | awk '$1 == "Mem:" {print $3}')
ram_percent=$(free --mega | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')

# free --mega: Displays memory usage information in megabytes.
# $1 == "Mem:": Checks if the line corresponds to total memory.
# print $2: Returns the total amount of RAM.
# print $3: Returns the amount of RAM in use.
# Percentage calculation: Uses the formula to calculate the percentage of RAM in use.

# DISK
disk_total=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_t += $2} END {printf ("%.1fGb\n"), disk_t/1024}')
disk_use=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} END {print disk_u}')
disk_percent=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} {disk_t+= $2} END {printf("%d"), disk_u/disk_t*100}')

# df -m: Displays disk usage information in megabytes.
# grep "/dev/": Filters lines that contain disk devices.
# grep -v "/boot": Excludes the /boot partition.
# Total and usage calculation: Accumulates usage and total values to calculate the percentage.

# CPU LOAD
cpul=$(vmstat 1 2 | tail -1 | awk '{printf $15}')
cpu_op=$(expr 100 - $cpul)
cpu_fin=$(printf "%.1f" $cpu_op)

# vmstat 1 2: Collects system information, including CPU load. The first execution is discarded.
# $15: The value in column 15 corresponds to the CPU idle time.
# 100 - $cpul: Calculates CPU load by subtracting idle time from 100%.

# LAST BOOT
lb=$(who -b | awk '$1 == "system" {print $3 " " $4}')

# who -b: Shows the date and time of the last system boot. The awk command filters the output to get only the date and time.

# LVM USE
lvmu=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)

# lsblk: Lists block devices.
# Checks if there is any entry related to LVM and stores "yes" or "no" in the variable lvmu.

# TCP CONNECTIONS
tcpc=$(ss -ta | grep ESTAB | wc -l)

# ss -ta: Shows information about TCP connections.
# grep ESTAB: Filters to count only established connections.

# USER LOG
ulog=$(users | wc -w)

# users: Lists currently logged-in users.
# wc -w: Counts the number of words, corresponding to the number of users.

# NETWORK
ip=$(hostname -I)
mac=$(ip link | grep "link/ether" | awk '{print $2}')

# hostname -I: Returns the machine's IP address.
# ip link: Lists information about network interfaces.
# grep "link/ether": Filters the line that contains the MAC address.

# SUDO
cmnd=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

# journalctl: Views system logs.
# Filters logs related to commands executed with sudo and counts how many were executed.

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

# wall: Sends a message to all logged-in users. The collected information is formatted and displayed.
sleep 600
done

