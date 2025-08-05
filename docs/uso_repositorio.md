## 🛠 Comandos para el uso del repositorio PIT 2025 - 6ta Edición

### 1. Instalación de Git
```bash
sudo apt update && sudo apt install git -y
```

### 2. Configuración inicial del workspace
```bash
# Crear el espacio de trabajo
mkdir -p ~/pit_ws/src

# Clonar el repositorio (desde la raíz del workspace)
cd ~/pit_ws
git clone https://github.com/morg1207/PIT-2025.git src

# Compilar el workspace
catkin_make

# Configurar el entorno
source devel/setup.bash
```

### 3. Configuración de VSCode
Revisa la guía completa de configuración:  
[📖 Configuración de VSCode para ROS](./configuracion_vscode.md)

---

## ⚠️ Solución de problemas

### Error de compilación
Si encuentras problemas al compilar, sigue estos pasos:

1. **Limpiar el workspace**:
```bash
cd ~/pit_ws
rm -rf build devel src
```

2. **Reclonar el repositorio**:
```bash
cd ~/pit_ws
rm -rf src/
git clone https://github.com/morg1207/PIT-2025.git src
catkin_make
```



