# Brick Breaker Game 🎮
A simple Brick Breaker game built using C++ and graphics.h.

## 🛠 Features
- 🎾 Classic Brick Breaker gameplay  
- 🏓 Paddle and ball mechanics  
- 🎨 Colorful bricks  
- 💯 Game over screen with a score display

## 🚀 Getting Started

### Prerequisites
- 🖥 **Windows OS**  
- 🛠 **C++ Compiler** (MinGW, Turbo C++, or MSVC)  
- 🎨 **graphics.h** library (for rendering) 

### Installation
Clone this repository:

1. **Clone the repository:**  
   ```bash
   git clone https://github.com/your-username/brickbreaker.git
   cd brickbreaker
   
2. **Compile the program:**  

      ```bash
      g++ brickbreaker.cpp -o brickbreaker -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32

2. **Run the game:** 
  
    ```bash
    ./brickbreaker
    
## 🎮 Controls
- Left Arrow (←) – Move paddle left
- Right Arrow (→) – Move paddle right
- Spacebar – Start game / Restart after game over

## 📷 Screenshots
![Screenshot 2025-03-31 091215](https://github.com/user-attachments/assets/87bfb68a-8093-4bca-b85f-2e514c0a5231)
![Screenshot 2025-03-31 091251](https://github.com/user-attachments/assets/5be1cac8-b7dc-46d6-90a5-bbdecc7d2eec)
![Screenshot 2025-03-31 091301](https://github.com/user-attachments/assets/045e9218-726a-4f32-a2f6-aa44526ef23d)


## 📝 To-Do List

 - Improve collision detection
 - Add power-ups
 - Implement different levels
 - Enhance UI

## 📌 Known Issues
- Game may not work on Linux/Mac due to graphics.h dependencies.
- Paddle movement speed might need adjustments or a difficulty setting can be added.
