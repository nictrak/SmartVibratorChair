import requests
import time
class Api :
    def __init__(self):
        self.state = 0
        self.nickname = "NA"
        self.steamkey = 'EDA30FBD3D850F4AA055FE4A99667537'
        self.gearkey = 'u7tUMhQ2r2IxQRN'
        self.gearsecret =  'yvBEiWBdJqicoHs4f0DPwrfnu'
        self.appid = 'SmartVibrationChair'
    def set_nickname(self, nickname):
        self.state = 1
        self.nickname = nickname
        
    def send_is_play(self):
        if self.state == 0 :
            return "wait"
        URL = 'http://api.steampowered.com/ISteamUser/ResolveVanityURL/v0001/'
        PARAMS = {'key':self.steamkey,'vanityurl': self.nickname}
        r = requests.get(url = URL, params = PARAMS)
        data = r.json()
        if data['response']['success'] != 1:
            return "error1"
        steamids = data['response']['steamid']
        URL = 'http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/'
        PARAMS = {'key':self.steamkey,'steamids': steamids}
        r = requests.get(url = URL, params = PARAMS)
        data = r.json()
        if(len(data["response"]["players"])<=0):
            return "error2"
        player = data["response"]["players"][0]
        if "gameextrainfo" in player.keys() :
            is_play = 1
        else :
            is_play = 0
        URL = 'https://api.netpie.io/feed/steamFeed'
        PARAMS = {'apikey':'J7lBkH2Nk1UzR2PegK2O7K2nrftsKc0Q','data':'isPlay:'+str(is_play)}
        requests.put(url = URL, params = PARAMS)
        return is_play
