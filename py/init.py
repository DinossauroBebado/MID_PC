from main import main
import web_config
import threading


if __name__ == "__main__":

    y = threading.Thread(target=main())
    y.start()
    run(port=8080)
