

from bottle import run, route, request
from config import read_config, write_config


@route('/', method="GET")
def index():
    lofi, rock = read_config()

    return f"""
        <form  action = "/" method = "post" >
        LOFI : <input name = "LOFI" type = "text" value= {lofi}>
        ROCK : <input name = "ROCK" type = "text"  value={rock}>
        <input value = "SAVE" type = "submit"/>
        </form>"""


@route('/', method="POST")
def index():
    lofi = request.forms.get("LOFI")
    rock = request.forms.get("ROCK")
    write_config(lofi, rock)
    print(lofi, rock)

    return f"""
        <form  action = "/" method = "post" >
        LOFI : <input name = "LOFI" type = "text" value= "{lofi}"/>
        ROCK : <input name = "ROCK" type = "text"  value="{rock}" />
        <input value = "SAVE" type = "submit"/>
        </form>"""


# run(port=8080)
