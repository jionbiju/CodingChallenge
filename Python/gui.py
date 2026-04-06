import tkinter as tk
from breezypythongui import EasyFrame
from datetime import datetime
class Color(EasyFrame):
    def __init__(self):
        EasyFrame.__init__(self,title="Favorite Color")
        self.addLabel(text="Name",row=0,column=0)
        self.name=self.addTextField(text="",row=0,column=1)
        self.addLabel(text="Birthday",row=1,column=0)
        self.birthday=self.addTextField(text="",row=1,column=1)
        self.addLabel(text="Favorite Color",row=2,column=0)
        self.color=self.addTextField(text="",row=2,column=1)
        self.addButton(text="submit",row=3,column=0,columnspan=2,command=self.show)
    
    def show(self):
        dob = self.birthday.getText()
        dob=dob.split('-')
        dob = datetime(int(dob[0]),int(dob[1]),int(dob[2]))
        cdt = datetime.now()
        age = cdt.year - dob.year
        if cdt.month < dob.month:
            age-=1
        self.messageBox(title="Biodata",message=self.name.getText()+"\n"+
                        str(age) + "\n" + self.color.getText())

Color().mainloop()