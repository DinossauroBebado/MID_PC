from spotify import pause, play, set_lofi, set_rock
import win32api
import win32gui
from win10toast import ToastNotifier

WM_APPCOMMAND = 0x319
APPCOMMAND_MICROPHONE_VOLUME_MUTE = 0x180000

toaster = ToastNotifier()


def lofi():
    """ My function to execute when a combination is pressed """
    print("lofi plays")
    #toaster.show_toast("LOFI", " ")
    set_lofi()


def rock():
    """ My function to execute when a combination is pressed """
    print("rock plays")
    #toaster.show_toast("ROCK", " ")
    set_rock()


def mute_mic():
    """ My function to execute when a combination is pressed """
    print("mute_mic")
    #toaster.show_toast("Mute Mic", " ")
    hwnd_active = win32gui.GetForegroundWindow()
    win32api.SendMessage(hwnd_active, WM_APPCOMMAND, None,
                         APPCOMMAND_MICROPHONE_VOLUME_MUTE)


def unmute_mic():
    """ My function to execute when a combination is pressed """
    print("unmute_mic")
    #toaster.show_toast("Unmute Mic", " ")
    hwnd_active = win32gui.GetForegroundWindow()
    win32api.SendMessage(hwnd_active, WM_APPCOMMAND, None,
                         APPCOMMAND_MICROPHONE_VOLUME_MUTE)


def play_music():
    """ My function to execute when a combination is pressed """
    print("play_music")
    #toaster.show_toast("Play Music", " ")
    play()


def pause_music():
    """ My function to execute when a combination is pressed """
    print("pause_music")
    #toaster.show_toast("Pause Music", " ")
    pause()


def fone():
    """ My function to execute when a combination is pressed """
    print("fone")
    #toaster.show_toast("Fone", " ")


def tv():
    """ My function to execute when a combination is pressed """
    print("tv")
    #toaster.show_toast("TV", " ")
