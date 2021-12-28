from MID_functions import fone, lofi, mute_mic, pause_music, play_music, rock, tv, unmute_mic
from pynput import keyboard

BASIC_KEYS_one = keyboard.KeyCode(vk=162)  # contrl left


# The key combinations to look for
COMBINATIONS = {

    124: lofi,
    125: rock,
    126: mute_mic,
    127: unmute_mic,
    128: play_music,
    129: pause_music,
    130: fone,
    131: tv,
}  # The currently pressed keys (initially empty)


def get_vk(key):
    """
    Get the virtual key code from a key.
    These are used so case/shift modifications are ignored.
    """
    return key.vk if hasattr(key, 'vk') else key.value.vk


def on_press(key):
    """ When a key is pressed """
    vk = get_vk(key)  # Get the key's vk

    if vk in COMBINATIONS:  # Loop though each combination
        # And check if all keys are pressed
        # If they are all pressed, call your function
        COMBINATIONS[vk]()
        # Don't allow execute to be called more than once per key press


def on_release(key):
    """ When a key is released """
    ...


with keyboard.Listener(on_press=on_press, on_release=on_release) as listener:
    # Join the listener thread to the current thread so we don't exit before it stops
    listener.join()
