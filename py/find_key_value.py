from pynput import keyboard


def get_vk(key):
    """
    Get the virtual key code from a key.
    These are used so case/shift modifications are ignored.
    """
    return key.vk if hasattr(key, 'vk') else key.value.vk


def on_release(key):
    """ When a key is released """
    vk = get_vk(key)  # Get the key's vk


def on_press(key):
    """ When a key is pressed """
    vk = get_vk(key)  # Get the key's vk
    print(vk)


with keyboard.Listener(on_press=on_press, on_release=on_release) as listener:
    # Join the listener thread to the current thread so we don't exit before it stops
    listener.join()
