import tkinter as tk

class DrawingApp:
    def __init__(self, root, rows=10, columns=10):
        self.root = root
        self.root.title("Canvas Drawer")

        # Calculate canvas dimensions based on rows and columns
        canvas_width = columns * 30
        canvas_height = rows * 30

        self.canvas = tk.Canvas(root, width=canvas_width, height=canvas_height, bg="white")
        self.canvas.grid(row=0, column=0, columnspan=2)

        self.submit_button = tk.Button(root, text="Submit", command=self.submit_drawing)
        self.submit_button.grid(row=1, column=0, columnspan=2)

        # Initialize an array to store the drawing
        self.drawing = [[0] * columns for _ in range(rows)]

        self.canvas.bind("<B1-Motion>", self.draw)

    def draw(self, event):
        x = event.x // 30
        y = event.y // 30

        # Ensure x and y are within the valid range
        if 0 <= x < len(self.drawing[0]) and 0 <= y < len(self.drawing):
            self.canvas.create_rectangle(x * 30, y * 30, (x + 1) * 30, (y + 1) * 30, fill="black")
            self.drawing[y][x] = 1

    def submit_drawing(self):
        flat_list = [item for sublist in self.drawing for item in sublist]
        # c_array = "{ "
        
        # for row in self.drawing:
        #     c_array += "    {" + ", ".join(map(str, row)) + "},\n"
        # c_array = c_array.rstrip(",\n") + "\n};"

        c_array = "{" + ", ".join(map(str, flat_list)) + "}"
        print(c_array)


        # Append the C array output to a file
        with open("drawing_output.txt", "a") as file:
            file.write("\n")
            file.write(c_array)

        # Clear the canvas and reset the drawing array
        self.canvas.delete("all")
        self.drawing = [[0] * len(self.drawing[0]) for _ in range(len(self.drawing))]

if __name__ == "__main__":
    root = tk.Tk()
    app = DrawingApp(root)
    root.mainloop()