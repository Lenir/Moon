---
layout: post
title:  "BLE Bus Notifier"
date:   2017-10-07
project: true
tag:
- BLE
- Beacon
- React Native
- 리액트 네이티브
feature: /assets/img/BLE_Bus_Notifier/Scene1_beaconDetected.png
comments: true
---
## Scene Flow
![SceneFlow](/assets/img/BLE_Bus_Notifier/SceneFlow.png)    

<center><b>Scene Flow Pic</b></center>
<center><b>장면 구성도</b></center>

Scenes' transactions is like above. let me write details scene by scenes.

## Scenes - Detail
 ![Scene0](/assets/img/BLE_Bus_Notifier/Scene0_rangingBeacon.png=300x)
 <center><b>Beacon Ranging Scene</b></center>
 First, 'Beacon Ranging Scene'. in this scene, app tries to detect bus' beacons. for find appropriate beacon, we use fixed UUID. if app detects **only one** suitable UUID, app automatically goes to Next Scene. when app finds **More than one** proper UUID, app shows list with Bus Number and its current location.(like above screenshot) I implement bus' number with iBeacon's 'Major' value and bus' location with 'Minor' value.

 ![Scene1](/assets/img/BLE_Bus_Notifier/Scene1_beaconDetected.png)
 <center><b>Bus Detail Scene - Destination not set</b></center>
 When app listens proper bus' beacon, app's beacon Listener add Major value to listen only one beacon. (so, UUID and Major value. e.g, *listening for beacon* UUID: **ABCDEFGH - EEEE - EEEE - EEEE - ABCDEFGHIJKL**, Major : **28**.) and app listens beacon's 'Minor' value changes. that means bus' location. I use euclidean distance for get where current bus' stop is. (this is not implemented in App part, but in Raspberry Pi - beacon part. not in repository. Sorry!) when Raspberry Pi determines that bus is at next stop, it changes beacon's 'Minor' value. and app receives that and shows it.
 App user have to select destination for get push notification. user can select destination with clicking '목적지 설정' button. it shows sidebar menu.

 ![Scene2](/assets/img/BLE_Bus_Notifier/Scene2_destinationSetting.png)
 <center><b>Bus Detail Scene - Destination setting</b></center>
 Sidebar menu for set destination. it shows favorite destination, and can select destination of course. app determines Favorite stop with your destination set history. dest set history implements with AsyncStorage(SQLite, local DB storage). with key(bus' Number, bus stop) - value(destination set counts) pair. When user set destination, app starts count remaining stops.

 ![Scene3](/assets/img/BLE_Bus_Notifier/Scene3_destinationIsSet.png)
 <center><b>Bus Detail Scene - Destination is set</b></center>
 App shows how many stops remain to destination. app refreshes state with received beacon advertisement and 'refreshState' function. if remaining stops is lesser then two, app sends push notification that remaining stops is few.

 ![Scene4](/assets/img/BLE_Bus_Notifier/Scene4_BackgroundPush1.png)
 <center><b>Background Push - destination is next stop!</b></center>
 App sends background push notification like above.( push message - *destination is next stop!*)

 ![Scene5](/assets/img/BLE_Bus_Notifier/Scene5_BackgroundPush_arrived.png)
  <center><b>Background Push - arrived to destination!</b></center>
App sends background push notification like above.( push message - *Arrived to destination!*)

![Scene6](/assets/img/BLE_Bus_Notifier/Scene6_ForegroundAlert.png)
 <center><b>Foreground Alert - arrived to destination!</b></center>
 When app is on foreground, app sends alert message.( alert message - *Arrived to destination!* )
