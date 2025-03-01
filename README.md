
## **📄 Updated README.md**
```md
# Linux Proc File Driver

This project demonstrates a **Linux kernel module** that creates a **proc file** (`/proc/Pyjama_driver`).  
The module supports **read/write** operations, allowing a user-space application (`user-app.py`) to communicate with the kernel.

---

## 🚀 Features
- **Proc file interaction** (`/proc/Pyjama_driver`).
- **Read/Write support** from user space.
- **Kernel message logging** (`dmesg`).
- **Multipass VM** for testing.
- **Python user-space applications** for interacting with the kernel.

---

## 🛠 Setup & Installation

### **1️⃣ Clone the Repository**
```sh
git clone https://github.com/garry00107/linux-proc-driver.git
cd linux-proc-driver
```

### **2️⃣ Build the Kernel Module**
```sh
make
```

### **3️⃣ Load the Module (`insmod`)**
```sh
sudo insmod ldd.ko
```

### **4️⃣ Verify the Module is Loaded (`lsmod`)**
```sh
lsmod | grep ldd
```
This command checks if the module is successfully loaded.

### **5️⃣ View Kernel Logs (`dmesg`)**
```sh
dmesg | tail -10
```
It shows recent kernel messages, including those from our module.

### **6️⃣ Clear Kernel Logs (`dmesg -c`)**
```sh
sudo dmesg -c
```
This clears kernel logs, useful for debugging new changes.

### **7️⃣ Read from the Proc File**
Run the **basic read application**:
```sh
python3 user-app.py
```
** Read & Write to the Proc File
Run the advanced read/write application:

python3 user-app-rw.py
Read from the driver: The app will display messages stored in the kernel.
Write to the driver: The app allows you to send messages to the kernel.

### **8️⃣ Read & Write to the Proc File**
Run the **advanced read/write application**:
```sh
python3 user-app-rw.py
```

### **9️⃣ Unload the Module (`rmmod`)**
```sh
sudo rmmod ldd
```

---

## 📂 Project Structure

```
📂 linux-proc-driver
├── 📄 ldd.c           # Kernel module source code (read & write support)
├── 📄 Makefile        # Compilation instructions
├── 📄 user-app.py     # Basic Python user-space application (read only)
├── 📄 user-app-rw.py  # Advanced Python app (read & write)
└── 📄 README.md       # Project documentation
```

---

## 📝 Code Explanation

### **Kernel Module (`ldd.c`)**
- Creates a **proc file** at `/proc/Pyjama_driver`.
- Implements **read** and **write** operations.
- Uses `proc_create()` and `proc_remove()` for file management.
- Logs messages using `printk()` (visible via `dmesg`).

### **Makefile**
- Compiles the **kernel module** using system headers.

### **User-Space Applications**
#### **1️⃣ `user-app.py` (Read-Only)**
- Opens `/proc/Pyjama_driver` and **reads messages** from the kernel.

#### **2️⃣ `user-app-rw.py` (Read/Write)**
- **Writes messages** to the kernel and **reads responses**.
- Helps test the **write functionality** of the proc file.

---

## 🔧 Troubleshooting

### **1️⃣ "insmod: ERROR: could not insert module: Invalid format"**
- Ensure you are using the correct **kernel version**:
  ```sh
  uname -r
  ```
- Recompile the module using:
  ```sh
  make clean && make
  ```

### **2️⃣ "Permission denied" when loading the module**
- Use `sudo` when running `insmod` or `rmmod`.

### **3️⃣ "No such file or directory" when accessing `/proc/Pyjama_driver`**
- Ensure the module is **loaded**:
  ```sh
  lsmod | grep ldd
  ```
- If missing, reload the module:
  ```sh
  sudo insmod ldd.ko
  ```

---

## 📜 License
This project is licensed under the **MIT License**.

---

## 🙌 Acknowledgments
- Developed as part of a **Linux Device Drivers** course.
- Tested using **Multipass** for virtualization.
```
<<<<<<< HEAD

---
=======
>>>>>>> 289b387 (Updated README, modified ldd.c, and added user-app-rw.py)

---
