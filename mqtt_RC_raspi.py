import  sys
from time import sleep
import paho.mqtt.client as mqtt
import serial
# ------------------------------------------------------------------
sys.stderr.write("*** 通信開始 ***\n")


ser = serial.Serial('接続するarduinoのポート',9600)

host = 'ブローカーのアドレス'
port = 1883
topic = 'mqtt_RC'


def on_connect(client, userdata, flags, respons_code):
    print('status {0}'.format(respons_code))

    client.subscribe(topic)

def on_message(client, userdata, msg):
    st = str(msg.payload,'utf-8')
    print(st)

    if st == "w":
        print("go_straight")
        ser.write(b'w')

    elif st == "s":
        print("stop")
        ser.write(b's')

    elif st == "d":
        ser.write(b'd')
        print("turn_righit")

    elif st == "a":
        ser.write(b'a')
        print("turn_left")

    elif st == "b":
        ser.write(b'b')
        print("go_back")

    elif st =="f":
        print("fin")
        client.disconnect()

if __name__ == '__main__':

    client = mqtt.Client(protocol=mqtt.MQTTv311)
    client.on_connect = on_connect
    client.on_message = on_message

    client.connect(host, port=port, keepalive=60)

    client.loop_forever()

sys.stderr.write("*** 終了 ***\n")
