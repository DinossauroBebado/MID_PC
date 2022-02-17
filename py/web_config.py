

from bottle import route, request
from config import read_config, write_config


@route('/', method="GET")
def index():
    lofi, rock = read_config()

    return f"""
        <style>
    input[type=text],
    select {{
        width: 100%;
        padding: 12px 20px;
        margin: 8px 0;
        display: inline-block;
        border: 1px solid #ccc;
        border-radius: 4px;
        box-sizing: border-box;
    }}

    input[type=submit] {{
        width: 100%;
        background-color: #4CAF50;
        color: white;
        padding: 14px 20px;
        margin: 8px 0;
        border: none;
        border-radius: 4px;
        cursor: pointer;
    }}

    input[type=submit]:hover {{
        background-color: #45a049;
    }}

    div {{
        border-radius: 5px;
        background-color: #f2f2f2;
        padding: 20px;
    }}
</style>

<form action="/" method="post">
    LOFI : <input name="LOFI" type="text" value={lofi}>
    ROCK : <input name="ROCK" type="text" value={rock}>
    <input value="SAVE" type="submit" />
</form>"""


@route('/', method="POST")
def index():
    lofi = request.forms.get("LOFI")
    rock = request.forms.get("ROCK")
    write_config(lofi, rock)
    print(lofi, rock)

    return f"""
            <style>
        input[type=text],
        select {{
            width: 100%;
            padding: 12px 20px;
            margin: 8px 0;
            display: inline-block;
            border: 1px solid #ccc;
            border-radius: 4px;
            box-sizing: border-box;
        }}

        input[type=submit] {{
            width: 100%;
            background-color: #4CAF50;
            color: white;
            padding: 14px 20px;
            margin: 8px 0;
            border: none;
            border-radius: 4px;
            cursor: pointer;
        }}

        input[type=submit]:hover {{
            background-color: #45a049;
        }}

        div {{
            border-radius: 5px;
            background-color: #f2f2f2;
            padding: 20px;
        }}
    </style>

    <form action="/" method="post">
        LOFI : <input name="LOFI" type="text" value={lofi}>
        ROCK : <input name="ROCK" type="text" value={rock}>
        <input value="SAVE" type="submit" />
    </form>"""
