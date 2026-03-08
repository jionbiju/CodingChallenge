# TCP and UDP Client–Server (C Socket Programming)

## Note

This project works **only in a Linux terminal** because it uses POSIX socket libraries such as:

* sys/socket.h
* arpa/inet.h
* netinet/in.h
* unistd.h

These libraries are not available in Windows by default.

## Running the Code on Windows

To run this project in Windows, you need a **Linux terminal environment**.
The recommended method is **WSL (Windows Subsystem for Linux)**.

### Step 1: Enable Virtualization

Before installing WSL, make sure **virtualization is enabled**.

1. Restart your computer and enter **BIOS settings**.
2. Find **Virtualization Technology (Intel VT-x / AMD-V)**.
3. Set it to **Enabled**.
4. Save and exit BIOS.

You can check if virtualization is enabled by:

1. Open **Task Manager**.
2. Go to **Performance → CPU**.
3. Check **Virtualization : Enabled**.

Also make sure **Virtual Machine Platform permission is enabled** in Windows:

1. Open **Control Panel**.
2. Go to **Programs → Turn Windows features on or off**.
3. Enable:

   * **Virtual Machine Platform**
   * **Windows Subsystem for Linux**
4. Click **OK** and restart the computer.

---

### Step 2: Install WSL

Open **PowerShell as Administrator** and run:

wsl --install

Restart your computer after installation.

---

### Step 3: Install Ubuntu

Run:

wsl --install -d Ubuntu

After installation, Ubuntu will open and ask you to create a **Linux username and password**.

---

### Step 4: Install GCC Compiler

Inside the Ubuntu terminal run:

sudo apt update <br>
sudo apt install build-essential

---

### Step 5: Compile the Program

Navigate to the project folder and compile:

gcc filename.c

---

### Step 6: Run the Program

./a.out

Now the **TCP and UDP socket programs will run exactly like in a Linux environment**.
