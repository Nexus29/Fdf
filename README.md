# 🗺️ FdF: Wireframe Model Representation (42 Project)

[![Graphics Badge](https://img.shields.io/badge/Library-MiniLibX-yellow)](https://en.wikipedia.org/wiki/Graphics_library)
[![Math Badge](https://img.shields.io/badge/Concepts-Isometric_Projection-blue)](https://en.wikipedia.org/wiki/Isometric_projection)

### 🌟 Project Overview

This repository contains **FdF** (Fil de Fer), a graphic project from the **42 Common Core curriculum**.

The goal of FdF is to read a map file containing elevation data and use the **MiniLibX** library to display this data as a **3D wireframe model** projected onto a 2D window. This project is a crucial step in understanding matrix transformations, linear algebra, and basic graphics programming.

#### **Key Concepts Covered:**
* **File Handling:** Parsing a map file (`.fdf`) to extract a grid of `(x, y, z)` coordinates.
* **MiniLibX:** Initializing a window, managing events (keyboard/mouse), and drawing pixels/lines.
* **Projection:** Applying a mathematical transformation (typically **isometric** or parallel projection) to convert 3D coordinates into 2D screen coordinates.
* **Line Drawing:** Implementing a line drawing algorithm (like **Bresenham's** or a variation) to connect points on the screen.

---

### 🖼️ Visual Examples

Here are several visualizations of the FdF program in action, showcasing different datasets and projection types:

| Isometric Terrain (Colored Wireframe) | Isometric Fractal (Solid Fill) | Top-Down Fractal (Grid View) |
| :---: | :---: | :---: |
| !['Screenshot of FdF showing a terrain map with colored elevation (blue for water, green/brown for land) in Isometric view.'](https://github.com/Nexus29/Fdf/blob/main/image/5.png) | !['Screenshot of FdF showing a complex, white, raised fractal shape on a red grid in Isometric view.'](https://github.com/Nexus29/Fdf/blob/main/image/1.png) | !['Screenshot of FdF showing a white fractal shape on a red grid in a flat, Top-Down view.'](https://github.com/Nexus29/Fdf/blob/main/image/4.png) |
| **Wireframe Coastline** | **Mandelbrot-like Shape** | **Terrain Wireframe** |
| !['Screenshot of FdF showing a wireframe grid of a terrain map with green and blue lines in Isometric view, resembling a coastline.'](https://github.com/Nexus29/Fdf/blob/main/image/2.png) | !['Screenshot of FdF showing a large, solid, white/gray fractal shape resembling a Mandelbrot set on a red grid in Isometric view.'](https://github.com/Nexus29/Fdf/blob/main/image/3.png) | !['Screenshot of FdF showing a terrain map with colored elevation (blue for water, green/brown for land) in Isometric view.'](https://github.com/Nexus29/Fdf/blob/main/image/5.png) |

---

### 🛠️ Installation and Usage

FdF requires the **MiniLibX** library, which is typically pre-installed or easily accessible on 42 school machines. It also relies on a correctly implemented **Libft** for utility functions.

1.  **Clone the Repository:**
    ```bash
    git@github.com:Nexus29/Fdf.git
    cd Fdf
    ```

2.  **Compile the Program:**
    Use the provided `Makefile` to compile the project.
    ```bash
    make
    ```
    This command will generate an executable file, usually named `fdf`.

3.  **Run with a Map File:**
    The program takes a map file (`.fdf`) as its single argument.
    ```bash
    ./fdf <path/to/map_file.fdf>
    ```

    **Example Map File (`test.fdf` format):**
    ```
    0 0 0 0
    0 5 5 0
    0 0 0 0
    ```

---

### ⌨️ Controls

The user should be able to interact with the wireframe model using keyboard controls.

| Key/Action | Functionality |
| :--- | :--- |
| **ESC** | Quit the program and close the window. |
| **Arrows** | Translate/Move the model across the screen (X and Y axis). |
| **'+' / '-'** | Zoom in / Zoom out. |
| **'P' / 'I'** | Switch between Parallel and Isometric projections. |
| **WASD / QEZX** | **(Bonus)** Rotate the model around the X, Y, or Z axis. |
| **Scroll Wheel** | **(Bonus)** Increase/decrease the Z-axis (height) factor. |

---

### 👤 Author

* **Giovanni Pio Lancellotta** - [Nexus29](https://github.com/Nexus29)
    * `42 Student ID:` **glancell**
    * `Personal Website:` *Coming Soon!*
