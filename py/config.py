import json


def read_config():
    with open('py/config.json') as cfg:
        data = json.load(cfg)

    lofi = data["spotify"]["lofi"]
    rock = data["spotify"]["rock"]
    return lofi, rock


def write_config(lofi_cont, rock_cont):
    config = {
        "spotify": {
            "lofi": lofi_cont,
            "rock": rock_cont
        }
    }

    json_object = json.dumps(config, indent=4)

    with open("py/config.json", "w") as outfile:
        outfile.write(json_object)
