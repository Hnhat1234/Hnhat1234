from tkinter import *
from PIL import Image, ImageTk

root = Tk()

root.title("MY APP")

Label(root, text = "24162072 Le Quang Minh", justify = CENTER, relief = SUNKEN).pack(pady = 10)

image = Image.open("profile.png.jpg")     
photo = ImageTk.PhotoImage(image)   

Label(root, image = photo, relief = RAISED).pack(side = LEFT, padx = 5)

root.minsize(height = 300, width = 400)

root.mainloop()