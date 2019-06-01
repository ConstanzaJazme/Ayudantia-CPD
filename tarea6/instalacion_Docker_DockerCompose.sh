#!/bin/bash

#Autor: Constanza Jazme
#Tarea n°6 de Ayudantia de Computación Paralela y Distribuida

echo -e "Script de instalación para Docker y Docker Compose"
echo -e "\n"

echo -e "Empezando instalación de Docker... \n"

echo -e "Previo a la instalación se debe eliminar cualquier versión anterior de Docker. \n"

sudo apt-get remove docker docker-engine docker.io

echo -e "\n 1) Importando clave GPG. \n"

#GPG: GNU PRIVACY GUARD, herramienta de cifrado de información mediante un par de claves.

sudo apt-key adv --keyserver hkp://p80.pool.sks-keyservers.net:80 --recv-keys 58118E89F3A912897C070ADBF76221572C52609D

echo -e "\n 2) Añadiendo repositorio. \n"

sudo apt-add-repository 'deb https://apt.dockerproject.org/repo ubuntu-xenial main'

echo -e "\n 3) Actualizando. \n"

sudo apt-get update

echo -e "\n 4) Instalando el paquete.\n"

sudo apt install docker-engine



echo -e "\nDocker fue instalado con éxito\n"
echo -e "\nEmpezando instalación de Docker Compose...\n"

echo -e "Es necesario instalar curl para lleva acabo la instalación exitosamente. \n"

sudo apt-get update

sudo apt-get install curl

echo -e "\n1) Ubicandose en /usr/local/bin/ \n"
cd /

cd /usr/local/bin/

echo -e "\n2) Descargar el binario de Docker Compose \n"
sudo curl -L "https://github.com/docker/compose/releases/download/1.23.1/docker-compose-$(uname -s)-$(uname -m)" -o /usr/local/bin/docker-compose

echo -e "\n3) Dando permiso de ejecutable al binario de Compose \n"

echo -e "\nSu versión de Docker es: \n"

docker --version

echo -e "\nSu versión de Docker Compose es: \n"

docker-compose --version

sudo chmod +x /usr/local/bin/docker-compose

echo -e "\nPara evitar el uso de sudo al momento de ejecutar el comando docker es necesario que añada su nombre de usuario"
echo -e "\n1) Se agrega el grupo docker.\n"
sudo groupadd docker

echo -e "\n2)Se agrega su usuario al grupo docker.\n"
sudo gpasswd -a $USER docker


echo -e "\n3)Se hace un cierre/inicio de sesión para activar los cambios.\n"
newgrp docker
