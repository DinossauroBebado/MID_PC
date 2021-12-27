from MID_functions import fone, lofi, mute_mic, pause_music, play_music, rock, tv, unmute_mic
from pynput import keyboard

BASIC_KEYS_one = keyboard.KeyCode(vk=162)  # contrl left
BASIC_KEYS_two = keyboard.KeyCode(vk=163)  # control right

# The key combinations to look for
COMBINATIONS = {

    (BASIC_KEYS_one, BASIC_KEYS_two, keyboard.KeyCode(vk=49)): lofi,
    (BASIC_KEYS_one, BASIC_KEYS_two, keyboard.KeyCode(vk=50)): rock,
    (BASIC_KEYS_one, BASIC_KEYS_two, keyboard.KeyCode(vk=51)): mute_mic,
    (BASIC_KEYS_one, BASIC_KEYS_two, keyboard.KeyCode(vk=52)): unmute_mic,
    (BASIC_KEYS_one, BASIC_KEYS_two, keyboard.KeyCode(vk=53)): play_music,
    (BASIC_KEYS_one, BASIC_KEYS_two, keyboard.KeyCode(vk=54)): pause_music,
    (BASIC_KEYS_one, BASIC_KEYS_two, keyboard.KeyCode(vk=55)): fone,
    (BASIC_KEYS_one, BASIC_KEYS_two, keyboard.KeyCode(vk=56)): tv,
}

# The currently pressed keys (initially empty)
pressed_vks = set()


def get_vk(key):
    """
    Get the virtual key code from a key.
    These are used so case/shift modifications are ignored.
    """
    return key.vk if hasattr(key, 'vk') else key.value.vk


def is_combination_pressed(combination):
    """ Check if a combination is satisfied using the keys pressed in pressed_vks """
    return all([get_vk(key) in pressed_vks for key in combination])


def on_press(key):
    """ When a key is pressed """
    vk = get_vk(key)  # Get the key's vk
    pressed_vks.add(vk)  # Add it to the set of currently pressed keys

    for combination in COMBINATIONS:  # Loop though each combination
        # And check if all keys are pressed
        if is_combination_pressed(combination):
            # If they are all pressed, call your function
            COMBINATIONS[combination]()
            break  # Don't allow execute to be called more than once per key press


def on_release(key):
    """ When a key is released """
    vk = get_vk(key)  # Get the key's vk
    pressed_vks.remove(vk)  # Remove it from the set of currently pressed keys


with keyboard.Listener(on_press=on_press, on_release=on_release) as listener:
    # Join the listener thread to the current thread so we don't exit before it stops
    listener.join()
