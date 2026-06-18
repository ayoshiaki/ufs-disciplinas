# Desenha apenas uma linha
# Ao desenhar outra, apaga a anterior

import tkinter as tk

def marca_inicio(event):
    global ini_x, ini_y
    ini_x = event.x
    ini_y = event.y

def atualiza_fim(event):
    global fim_x, fim_y
    fim_x = event.x
    fim_y = event.y
    canvas.delete("all")
    canvas.create_line(ini_x, ini_y, fim_x, fim_y)


root = tk.Tk()

canvas = tk.Canvas(root, bg='white', width=600, height=600)
canvas.pack()

ini_x = None  # coordenadas do ponto inicial da linha
ini_y = None
fim_x = None
fim_y = None
canvas.bind('<ButtonPress-1>', marca_inicio)
canvas.bind('<B1-Motion>', atualiza_fim)
#canvas.bind('<ButtonRelease-1>', reset)

root.mainloop()
