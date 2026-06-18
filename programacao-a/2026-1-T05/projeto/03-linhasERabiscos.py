import tkinter as tk
from tkinter import ttk

# Quando mouse é pressionado
def iniciar_figura_nova(event):
    global figura_nova
    if tipo_figura_var.get() == 'Linha':
        figura_nova = ("linha", (event.x, event.y, event.x, event.y))
    else :
        figura_nova = ("rabisco", [(event.x, event.y)])

# Quando mouse é movido com o botão pressionado
def atualizar_figura_nova(event):
    global figura_nova
    if figura_nova[0] == "rabisco":
        figura_nova[1].append((event.x, event.y))
    else : # figura_nova[0] == "linha"
        figura_nova = ("linha", (figura_nova[1][0], figura_nova[1][1], event.x, event.y))
    desenhar()
    desenhar_figura_nova()

# Quando mouse é solto
def incluir_figura_nova(event):
    if not incompleta(figura_nova): # para evitar incluir figuras incompletas, como uma linha sem comprimento ou um rabisco com um único ponto
        figuras.append(figura_nova)
    desenhar()

def desenhar():
    canvas.delete("all")
    for fig, values in figuras:
        if fig == "linha":
            canvas.create_line(values[0], values[1], values[2], values[3])
        else : # fig == "rabisco"
            canvas.create_line(values)

def desenhar_figura_nova():
    fig, values = figura_nova
    if fig == "linha":
        canvas.create_line(values[0], values[1], values[2], values[3], dash=(4, 2))
    else : # fig == "rabisco"
        canvas.create_line(values, dash=(4, 2))

def incompleta(figura):
    fig, values = figura
    if fig == "linha":
        return (values[0], values[1]) == (values[2], values[3])
    else : # fig == "rabisco"
        return len(values) <= 1


figuras = []       # Todas as figuras desenhadas
figura_nova = None # Figura que está sendo desenhada, mas ainda não foi incluída em figuras


def main():
    global canvas, tipo_figura_var

    root = tk.Tk()
    frame = tk.Frame(root)

    # Widgets arranjados com Layout grid dentro de frame
    paddings = {'padx': 5, 'pady': 5}

    # label
    label = ttk.Label(frame, text='Linha ou Rabisco:')
    label.grid(column=0, row=0, sticky=tk.W, **paddings)

    # option menu
    tipo_figura_var = tk.StringVar(root) # Guarda o tipo de figura selecionado no option menu (linha ou rabisco)
    option_menu = ttk.OptionMenu(frame, tipo_figura_var,
                                 'Linha', 'Linha', 'Rabisco')
    option_menu.grid(column=1, row=0, sticky=tk.W, **paddings)

    # Área de desenho
    canvas = tk.Canvas(frame, bg='white', width=600, height=600)
    canvas.grid(column=0, row=1, columnspan=2, sticky=tk.W, **paddings)

    frame.pack()

    # Eventos de mouse associados ao canvas - com seus callbacks
    canvas.bind('<ButtonPress-1>', iniciar_figura_nova)
    canvas.bind('<B1-Motion>', atualizar_figura_nova)
    canvas.bind('<ButtonRelease-1>', incluir_figura_nova)

    root.mainloop()


if __name__ == "__main__":
    main()
