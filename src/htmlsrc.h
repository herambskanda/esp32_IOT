#define htmlsrc "\
<html>\
  <head>\
    <meta http-equiv='refresh' content='4'/>\
    <meta name='viewport' content='width=device-width, initial-scale=1'>\
    <title>ESP32 DHT Server</title>\
    <style>\
    html { font-family: Arial; display: inline-block; margin: 0px auto; text-align: left;}\
    h2 { font-size: 2.0rem; }\
    p { font-size: 1.0rem; }\
    .units { font-size: 1.2rem; }\
    .dht-labels{font-size: 1.5rem; vertical-align:middle; padding-bottom: 15px;}\
    .us-labels{font-size: 1.5rem; vertical-align:middle; padding-bottom: 15px;}\
    .weight-labels{font-size: 1.5rem; vertical-align:middle; padding-bottom: 15px;}\
    </style>\
  </head>\
  <body>\
      <h2>TRASHBIN SERVER</h2>\
      <p>\
        <span class='dht-labels'>Temperature</span>\
        <span>%.2f</span>\
        <sup class='units'>&deg;C</sup>\
      </p>\
      <p>\
        <span class='dht-labels'>Humidity</span>\
        <span>%.2f</span>\
        <sup class='units'>&percnt;</sup>\
      </p>\
      <p>\
        <span class='us-labels'>distance on device x</span>\
        <span>%.2f</span>\
        <sup class='units'>m;</sup>\
      </p>\
      <p>\
        <span class='weight-labels'>weight</span>\
        <span>%.2f</span>\
        <sup class='units'>g;</sup>\
      </p>\
  </body>\
</html>"