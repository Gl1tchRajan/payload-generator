**Payload Generator CLI Tool:**

A modular command-line payload generation tool written in C.
This project demonstrates structured software design, argument validation, encryption handling, logging mechanisms, and secure file output management.
It is designed for educational purposes in cybersecurity and systems programming.

**Overview:**
The Payload Generator CLI Tool allows users to:
1. Generate payloads of custom size
2. Choose different payload generation modes
3. Apply encryption (XOR / optional ChaCha20 upgrade)
4. Save payloads to structured output directories
5. Maintain execution logs
6. Handle invalid arguments safely
7. Compile easily using a Makefile

This project follows modular C architecture with proper header separation.

**Features:**
1. Command-line argument parsing
2. Size validation and input validation
3. Error handling with clear messages
4. Random & structured payload generation
5. XOR encryption support
6. Optional ChaCha20 upgrade (future enhancement)
7. Automatic output file creation
8. Logging system
9. Modular project structure
10. Clean build system with Makefile

**Technologies Used:**
1. C Programming Language
2. GCC Compiler
3. Makefile (Build Automation)
4. Linux/Kali Environment
5. Standard C Libraries

**Installation:**
Clone the Repository
```
git clone https://github.com/Gl1tchRajan/Payload-Generator.git
cd Payload-Generator
Build the Project
make
```

**Usage:**
Run the tool using:
```
./payload -s <size> -m <mode> -o <output_file> -k <key>
```

**Example commands:**
```
./payload -s 50 -m random -o test.bin -k secret
./payload -h
./payload -s -10 -m wrong
```
**Logging System:**
```
logs/
```
Logs include:

1. Timestamp
2. Payload size
3. Mode used
4. Output filename
5. Execution status

**Encrptytion:**
Currently implemented:
 XOR encryption
Optional future enhancement:
 Real ChaCha20 stream cipher implementation

 **Error Handling & Validation:**
The program validates:
1. Missing arguments
2. Invalid size values
3. Unsupported modes
4. File creation errors
5. Memory allocation failures

Clear error messages are displayed to ensure safe usage.

**Future Improvements:**
1. Full ChaCha20 implementation
2. Additional encryption modes
3. Unit testing
4. Cross-platform compatibility
5. Interactive CLI mode
6. CI/CD integration

**Project Structure:**
```
Payload-Generator/
│
├── src/              # Source files
├── include/           # Header files
├── logs/              # Generated log files
├── output/            # Generated payload files
├── Makefile           # Build automation
├── README.md          # Documentation
└── LICENSE            # License information
```

**What I Learned:**
Building this project improved my skills in:
1. Structuring medium-sized C projects
2. Writing modular and maintainable code
3. Managing memory efficiently
4. Handling file operations securely
5. Implementing basic encryption algorithms
6. Understanding how payload generation works internally
7. Automating compilation with Makefile
8. This project helped me connect theoretical cybersecurity knowledge with real-world implementation.

**Screenshots:**
Screenshot 1: Project Structure
<img width="750" height="297" alt="image" src="https://github.com/user-attachments/assets/5f0397dc-bc17-4261-8289-013a25342c16" />

Screenshot 2: Compilation
<img width="750" height="138" alt="image" src="https://github.com/user-attachments/assets/4ef2b1c6-9e81-438e-b523-e576205f5eab" />

Screenshot 3: Help Menu
<img width="750" height="216" alt="image" src="https://github.com/user-attachments/assets/0f6536dc-4227-4f0a-b27b-61db76901b1b" />

Screenshot 4: Successful Payload Generation
<img width="750" height="178" alt="image" src="https://github.com/user-attachments/assets/ca7e75b6-c007-42c9-afe5-0c8cc24c613d" />

Screenshot 5: Error Handling Example
<img width="750" height="81" alt="image" src="https://github.com/user-attachments/assets/fbd817c8-245d-4d86-8794-90298cce88f9" />

**Future Improvements**
1. Full ChaCha20 implementation
2. Additional encryption modes
3. Unit testing
4. Cross-platform compatibility
5. Interactive CLI mode
6. CI/CD integration

**Contributing:**
Contributions are welcome!
If you'd like to improve the project:
1. Fork the repository
2. Create a new branch
3. Improve features or fix bugs
4. Submit a pull request

**Disclaimer:**
This project is developed strictly for educational purposes.
It was created to learn system programming and encryption concepts. It should not be used for illegal, malicious, or unauthorized activities.

**Author:**
Rajan Kumar Mahato Tharu 
<p align="center">
  <img src="https://readme-typing-svg.herokuapp.com?color=00FF00&size=23&center=true&vCenter=true&width=700&lines=Cybersecurity+Student;C+Programmer;Linux+Enthusiast;Ethical+Hacking+Learner;Building+Low-Level+Security+Tools" />
</p>

[![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Linux](https://img.shields.io/badge/Linux-000000?style=for-the-badge&logo=linux)](https://www.kernel.org/)
[![Git](https://img.shields.io/badge/Git-F05032?style=for-the-badge&logo=git)](https://git-scm.com/)
[![GitHub](https://img.shields.io/badge/GitHub-181717?style=for-the-badge&logo=github)](https://github.com/Gl1tchRajan)
