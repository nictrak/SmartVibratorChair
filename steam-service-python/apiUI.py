from tkinter import *
from steamUpdater import Api
import threading
import time
import microgear.client as client
api = Api()
main = Tk()
sv = StringVar()
playerLabel = Label(main, textvariable = sv)
playerLabel.grid(row=0,column=0)
sv.set('current steam user : ' + api.nickname)
setPlayer = Label(main, text = "New Nickname : ")
setPlayer.grid(row=1, column=0)
setPlayerInput = Entry(main, text='NewNickname')
setPlayerInput.grid(row=1, column=1)
def apply_change():
    api.set_nickname(setPlayerInput.get())
    sv.set('current steam user : ' + api.nickname)
setPlayerButton = Button(main, text='Apply Change', command = apply_change)
setPlayerButton.grid(row=2,column=0)  
def put_thread():
    client.create(api.gearkey,api.gearsecret,api.appid,{'debugmode': True})
    client.connect()
    while True:
        time.sleep(9)
        res = api.send_is_play()
        client.chat("nodemcu","isplay:"+str(res))
        print(res)
x = threading.Thread(target=put_thread)
x.start()
main.mainloop()
    