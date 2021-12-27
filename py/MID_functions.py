from spotify import pause, play, set_lofi, set_rock
import win32api
import win32gui


WM_APPCOMMAND = 0x319
APPCOMMAND_MICROPHONE_VOLUME_MUTE = 0x180000


def lofi():
    """ My function to execute when a combination is pressed """
    print("lofi plays")
    set_lofi()


def rock():
    """ My function to execute when a combination is pressed """
    print("rock plays")
    set_rock()


def mute_mic():
    """ My function to execute when a combination is pressed """
    print("mute_mic")

    hwnd_active = win32gui.GetForegroundWindow()
    win32api.SendMessage(hwnd_active, WM_APPCOMMAND, None,
                         APPCOMMAND_MICROPHONE_VOLUME_MUTE)


def unmute_mic():
    """ My function to execute when a combination is pressed """
    print("unmute_mic")

    hwnd_active = win32gui.GetForegroundWindow()
    win32api.SendMessage(hwnd_active, WM_APPCOMMAND, None,
                         APPCOMMAND_MICROPHONE_VOLUME_MUTE)


def play_music():
    """ My function to execute when a combination is pressed """
    print("play_music")
    play()


def pause_music():
    """ My function to execute when a combination is pressed """
    print("pause_music")
    pause()


def fone():
    """ My function to execute when a combination is pressed """
    print("fone")


def tv():
    """ My function to execute when a combination is pressed """
    print("tv")
