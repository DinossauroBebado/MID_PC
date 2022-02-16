from spotipy.oauth2 import SpotifyOAuth
import spotipy
import keys
from keys import device_id
import config


scope = "user-read-playback-state,user-modify-playback-state"
"Config credencials for the API"
sp = spotipy.Spotify(client_credentials_manager=SpotifyOAuth(scope=scope))

" Shows playing devices"
#res = sp.devices()
# print(res)


def play():
    "start playing music"
    sp.volume(100, device_id)


def pause():
    "stop playing music"
    sp.volume(0, device_id)


def set_rock():
    "set the more energing playlist"
    sp.volume(80, device_id)
    _, rock = config.read_config()
    print(rock)
    sp.start_playback(device_id=device_id,
                      context_uri=rock)


def set_lofi():
    "set the more focus playlist"
    sp.volume(50, device_id)
    lofi, _ = config.read_config()
    sp.start_playback(device_id=device_id,
                      context_uri=lofi)
