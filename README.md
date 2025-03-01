# linux-proc-driver
A simple Linux device driver using proc files with a Python user-space application.

# linux-proc-driver
A simple Linux device driver using proc files with a Python user-space application.



# Linux Proc File Driver

This project demonstrates a simple **Linux kernel module** that creates a **proc file** (`/proc/Pyjama_driver`). The module supports **read** operations, allowing a user-space application (`user-app.py`) to communicate with the kernel.

## 🚀 Features
- Creates a **proc file** (`/proc/Pyjama_driver`).
- Supports **read operations** from user space.
- Written in **C** for the kernel module and **Python** for the user-space application.
- Uses **Multipass** for Ubuntu virtual machine execution.

---

## 🛠 Setup & Installation

### **1️⃣ Clone the Repository**

git clone https://github.com/garry00107/linux-proc-driver.git
cd linux-proc-driver
```

### **2️⃣ Build the Kernel Module**
```
make
```

### **3️⃣ Load the Module**
```
sudo insmod ldd.ko
```

### **4️⃣ Verify the Module is Loaded**
```
lsmod | grep ldd
```

### **5️⃣ Check the Kernel Logs**
```
dmesg | tail -10
```

### **6️⃣ Read from the Proc File**
Run the user-space Python application:
```
python3 user-app.py


### **7️⃣ Unload the Module**

sudo rmmod ldd
``

---

## 📂 Project Structure

``
📂 linux-proc-driver
├── 📄 ldd.c           # Kernel module source code
├── 📄 Makefile        # Compilation instructions
├── 📄 user-app.py     # Python user-space application
└── 📄 README.md       # Project documentation
``

---

## 📝 Code Explanation

### **Kernel Module (`ldd.c`)**
- Creates a proc file (`/proc/Pyjama_driver`).
- Implements **read** operation (`pyjama_read`).
- Uses `proc_create()` and `proc_remove()` to manage the file.

### **Makefile**
- Compiles the kernel module using the **Linux kernel headers**.

### **User-Space Application (`user-app.py`)**
- Opens `/proc/Pyjama_driver` and reads data from the kernel.

---

## 🔧 Troubleshooting
### **"insmod: ERROR: could not insert module: Invalid format"**
- Ensure you are using the correct **kernel version**:
  
  uname -r
  ```
- Recompile using:
  
  make clean && make
  ```

### **"Permission denied" when loading the module**
- Use `sudo` when running `insmod` or `rmmod`.

---

## 📜 License
This project is licensed under the **MIT License**.

---

## 🙌 Acknowledgments
- Inspired by **Linux Device Drivers** course.
- Developed using **Multipass** for virtualization.
  

