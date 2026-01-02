# Neo Flux

**Neo Flux** is a high-performance, aesthetically pleasing music visualizer written in C. Designed for both casual listening and content creation, it transforms your audio into stunning, real-time visual experiences.

## 🌟 Features

Neo Flux comes packed with advanced features to visualize your music exactly how you want:

- **Diverse Visualizers**: Choose from **10+** distinct visualization modes, each offering a unique perspective on your audio:
  - **Bars**: Classic frequency bars with smooth interpolation.
  - **Circle**: A pulsating circular representation.
  - **Wave**: Oscilloscope-style waveform visualization.
  - **Spectrum**: Detailed frequency spectrum analysis.
  - **Particles**: Reactive particle system that dances to the beat.
  - **Radial**, **Mirror**, **Spiral**, **Grid**, **Pulse**, and more!
- **High-Fidelity Audio Analysis**: Utilizes **Fast Fourier Transform (FFT)** for precise frequency breakdown, with custom smoothing and smearing algorithms for a fluid visual response.
- **Real-time Microphone Input**: Switch seamlessly to microphone capture (`C` key) to visualize live audio, voice, or ambient sound.
- **Video Rendering**: Built-in support for rendering your visualization sessions to high-quality video files using **FFmpeg**. Perfect for creating music videos.
- **Hot Reloading**: (For Developers) Modify the visualization logic in `src/plug.c` and compile while the app is running to see changes instantly without restarting.
- **Zero-Friction UI**: Minimalist, keyboard-driven interface with a clean HUD and tooltip system.

## 🎮 Controls

The application is designed to be controlled primarily via keyboard shortcuts for quick access during performance or relaxation.

| Key       | Function      | Description                                                       |
| :-------- | :------------ | :---------------------------------------------------------------- |
| **SPACE** | Play / Pause  | Toggle music playback.                                            |
| **F**     | Fullscreen    | Toggle fullscreen mode.                                           |
| **R**     | Render        | Start or stop rendering the current session to a video file.      |
| **C**     | Capture / Mic | Toggle microphone input (Capture mode).                           |
| **M**     | Mute          | Toggle audio mute.                                                |
| **H**     | Hot Reload    | Reload the visualization code (requires recompilation of `plug`). |
| **ESC**   | Close         | Exit the application.                                             |

## 🛠️ Building from Source

Neo Flux uses a zero-dependency build system based on `nob` (Nobuild). You don't need Make, CMake, or other complex build tools—just a C compiler.

### Prerequisites

- **C Compiler**: MSVC (Windows), GCC, or Clang.
- **FFmpeg** (Optional): Required in your system PATH if you want to use the video rendering feature.

### Build Steps

1.  **Clone the repository:**

    ```bash
    git clone https://github.com/yourusername/my_musializer.git
    cd my_musializer
    ```

2.  **Bootstrap the build system:**

    - **Windows (MSVC):**
      Open a "Native Tools Command Prompt for VS" and run:

      ```cmd
      cl nob.c
      ```

    - **Linux / macOS:**
      ```bash
      cc nob.c -o nob
      ```

3.  **Build the application:**

    - **Windows:**

      ```cmd
      nob.exe
      ```

    - **Linux / macOS:**
      ```bash
      ./nob
      ```

    This will compile `raylib`, the core application, and the plugin system, placing the result in the `build/` directory.

4.  **Run:**
    ```cmd
    build\musializer.exe
    ```
    (Or the equivalent executable on your platform).

## 🧩 Technical Details

### Architecture

The project is built on a "Core + Plugin" architecture:

- **`musializer.c`**: The host application. It handles window creation, input management, and loading the plugin.
- **`plug.c`**: The "brain" of the operation. Contains all visualization logic, rendering code, and audio processing. This compiles to a shared library (`.dll` or `.so`) that can be reloaded at runtime.

### Audio Processing

Neo Flux uses a custom FFT implementation to break down audio signals. The raw frequency data goes through several stages of processing:

1.  **Hann Windowing**: To reduce spectral leakage.
2.  **Logarithmic Scaling**: To match the human ear's non-linear perception of pitch.
3.  **Smoothing**: Time-based interpolation to remove jitter.
4.  **Smearing**: A trailing effect for visual continuity.

## 👨‍💻 Credits

**Created & Maintained by [Your Name]**

This project is the result of dedicated work in graphics programming and signal processing.

### Acknowledgments

- Powered by [Raylib](https://www.raylib.com/) for graphics.
- Based on principles from the open-source community.
- Special thanks to the creators of Miniaudio and FFmpeg.

---

_Generated for the Neo Flux project._
