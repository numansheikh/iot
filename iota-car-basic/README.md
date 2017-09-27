# ESP8266 based Wifi Controlled Car
This is a very barebone skeleton of code for converting your toy car to an iot device. 
Detailed explaination is given at these blog posts. 
- https://numan.space/2017/09/26/converting-a-simple-electric-car-into-an-iot-enabled-car
- https://medium.com/@numan.sheikh/converting-a-simple-electric-car-into-a-iot-enabled-car-aa161c75695e

We assume thatyou have installed the ESP8266 support in the Arduino IDE.
After uploading this code to NodeMCU/Wemos device, connect your laptop or tablet or phone to a wifi named *iotacar-AP* and there is no password. 

Open a browser and type the following (self explanatory) URL’s into the address bar:

- http://iotacar.local/go-forward
- http://iotacar.local/go-back
- http://iotacar.local/go-left
- http://iotacar.local/go-right
- http://iotacar.local/stop
