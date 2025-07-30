# **Guía de Instalación de WSL con Ubuntu 20.04 (ROS Noetic)**  
**Curso de Robótica**  

---

## **Requisitos previos**  
✅ **Sistema Operativo:** Windows 10 (versión 2004 o superior) o Windows 11.  
✅ **Virtualización habilitada en BIOS/UEFI** (imprescindible para WSL2).  

---

## **Paso 1: Verificar virtualización**  
Antes de instalar WSL, asegúrate de que la virtualización esté activada.  

### **Cómo comprobarlo:**  
1. Abre el **Administrador de tareas** (`Ctrl + Shift + Esc`).  
2. Ve a la pestaña **"Rendimiento"**.  
3. Busca **"Virtualización"** en la parte inferior:  
   - Si dice **"Habilitado"**, continúa al **Paso 2**.  
   - Si dice **"Deshabilitado"**, actívalo en el BIOS/UEFI.  

### **Activación en BIOS/UEFI (si es necesario)**  
- **Windows 10:** [Video tutorial](https://www.youtube.com/watch?v=tgH4_jkiMbc)  
- **Windows 11:** [Video tutorial](https://www.youtube.com/watch?v=N8MiDmyEdsQ)  

🔹 **Nota:** La tecla para entrar al BIOS varía (F2, F10, DEL, ESC, etc.).  

---

## **Paso 2: Instalar WSL y Ubuntu 20.04**  
Sigue estos pasos para instalar **Ubuntu 20.04** (requerido para ROS Noetic).  
- Video Guía  [Video tutorial](https://www.youtube.com/watch?v=Qy44XLpiChc).
Revisar solo hasta el min 2.04.

### **1. Instalar WSL desde PowerShell (como Administrador)**  
1. Presiona `Windows + X` y selecciona **"Terminal (Admin)"**.  
2. Ejecuta:  
   ```powershell
   wsl --install
   ```
   (Esto instalará WSL2 por defecto).  

### **2. Instalar Ubuntu 20.04 específicamente**  
Ejecuta:  
```powershell
wsl --install -d Ubuntu-20.04
```  

### **4. Configura usuario y contraseña**  
La primera vez que descargues Ubuntu, se te pedirá crear un usuario y contraseña (anótalos).  

### **3. Reinicia tu computadora**  
Después de la instalación, reinicia para aplicar los cambios.  



## **Paso 3: Verificar instalación**  
1. Abre PowerShell y ejecuta:  
   ```powershell
   wsl -l -v
   ```  
   Deberías ver:  
   ```
   NAME            STATE      VERSION  
   Ubuntu-20.04    Running    2  
   ```  
2. Para entrar a Ubuntu, ejecuta:  

    Configurar como predeterminado Ubuntu20.04
    ```powershell
    wsl --set-default Ubuntu-20.04
    ```  
    Para entrar a Ubuntu, ejecuta: 
   ```powershell
   wsl
   ```  

