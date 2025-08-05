# **📦 Instalación de ROS Noetic en WSL/Ubuntu 20.04**

Guía oficial para configurar ROS Noetic en el entorno del curso PIT 2025.

## **Prerrequisitos**
- WSL2 con Ubuntu 20.04 ([Guía de instalación](./Instalar_wsl.md))
- Mínimo 4GB de RAM asignados a WSL
- Conexión a Internet estable

---

## **🔧 Instalación Paso a Paso**

### **1. Configurar repositorios**
```bash
sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'

sudo apt install curl # if you haven't already installed curl

curl -s https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | sudo apt-key add -
```

### **2. Actualizar paquetes**
```bash
sudo apt update && sudo apt upgrade -y
```

### **3. Instalar ROS Noetic (versión completa)**
```bash
sudo apt install ros-noetic-desktop-full -y
```

### **4. Configurar entorno**
```bash
echo "source /opt/ros/noetic/setup.bash" >> ~/.bashrc
source ~/.bashrc
```

### **5. Instalar dependencias básicas**
```bash
sudo apt install python3-rosdep python3-rosinstall python3-rosinstall-generator python3-wstool build-essential -y

sudo apt install python3-rosdep

sudo rosdep init
rosdep update
```

---

## **✅ Verificación de la Instalación**
Ejecuta estos comandos para confirmar que todo funciona:

1. **Prueba el master de ROS**:
   ```bash
   roscore
   ```
   (Presiona `Ctrl+C` para salir)

2. **Demo con Turtlesim**:
   ```bash
   rosrun turtlesim turtlesim_node
   ```
---

## **🚀 Siguientes Pasos**

1. [Clonar y uso del repositorio del curso](./uso_repositorio.md)

---