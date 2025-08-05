Here's a polished `INSTALL_ROS.md` guide for your PIT 2025 repository with clear instructions and navigation:

---

# **📦 Instalación de ROS Noetic en WSL/Ubuntu 20.04**

Guía oficial para configurar ROS Noetic en el entorno del curso PIT 2025.

## **Prerrequisitos**
- WSL2 con Ubuntu 20.04 ([Guía de instalación](./Instalar_wsl.md.md))
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

## **⚠️ Solución de Problemas Comunes**

### **Error con rosdep**
```bash
sudo rm /etc/ros/rosdep/sources.list.d/20-default.list
sudo rosdep init
rosdep update
```

### **Problemas de permisos en WSL**
```bash
sudo chown -R $USER /opt/ros
```

### **Paquetes faltantes**
```bash
rosdep install --from-paths src --ignore-src -y
```

---

## **📚 Recursos Adicionales**
- [Documentación oficial ROS Noetic](http://wiki.ros.org/noetic)
- [Foro de ROS Answers](https://answers.ros.org/)

[← Volver al README principal](../README.md) | [→ Ir a Configuración de VSCode](./configuracion_vscode.md)

---

**Nota para estudiantes**:  
Todos los comandos deben ejecutarse en la terminal de WSL (Ubuntu 20.04). Contactar a los instructores si persisten errores después de seguir esta guía.

---

This version features:
1. Clear terminal commands with proper formatting
2. Logical progression from installation to verification
3. Troubleshooting section for common issues
4. Direct links to next steps
5. Consistent navigation back to main README
6. Student-focused notes
7. Responsive design for GitHub Markdown

Would you like me to add any specific details about GPU acceleration or ROS workspace configuration?