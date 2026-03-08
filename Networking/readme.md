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

### Step 1: Install WSL

Open **PowerShell as Administrator** and run:

wsl --install

Restart your computer after installation.

### Step 2: Install Ubuntu

Run:

wsl --install -d Ubuntu

After installation, Ubuntu will open and ask you to create a **Linux username and password**.

### Step 3: Install GCC Compiler

Inside the Ubuntu terminal run:

sudo apt update <br>
sudo apt install build-essential

### Step 4: Compile the Program

Navigate to the project folder and compile:

gcc filename.c

### Step 5: Run the Program

./a.out

Now the **TCP and UDP socket programs will run exactly like in a Linux environment**.
