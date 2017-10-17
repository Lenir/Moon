
이 포스팅은 한국어, 영어로 적혀 있습니다. 위 셀렉트 박스에서 언어 설정이 가능합니다. 형편없는 영어 실력 양해 바랍니다.<br>
This posting is written in both Korean, English. You can select language with 'select box', above this article. excuse my poor english.<br><br>

---

## Project Synopsis
This project's goal is build service that provides bus location which user want to be notified, and notify it to user via push notification.<br><br>

---

## Used/Referenced
1. [**React native**](http://facebook.github.io/react-native/) - facebook<br>
facebook's mobile app dev framework. good for fast mobile app realization, and good performance!(compare with other 'hybrid app')<br>
   1. [**React native Korean Tutorial**](https://www.gitbook.com/book/g6ling/react-native-tutorial-korean)<br>facebook's React native Doc is good enough, but this Tutorial doc is more comfortable for developer who uses korean in native.<br>
   2. [**React native router flux**](https://github.com/aksonov/react-native-router-flux)<br>
   Scene control<br>
   3. [**React native beacons manager**](https://github.com/MacKentoch/react-native-beacons-manager)<br>
   Beacon Listeners<br>
   4. [**React native background timer**](https://github.com/ocetnik/react-native-background-timer)<br>Background timer for push notification<br>
   5. [**React native push notification**](https://github.com/zo0r/react-native-push-notification)<br>mobile native(iOS, Android) push notification library<br>
   6. [**React native Elements**](https://github.com/react-native-training/react-native-elements)<br>Awesome UI Library!<br>
2. **Raspberry Pi** - School provides to us. old version.(no Wifi, no bluetooth, no gps.)<br>
   1. **GPS module**<br>with external antenna.<br>
   2. **Bluetooth Low Energy(BLE) module**<br>beacon broadcasting. we use iBeacon standard.<br><br>

---

## Scene Flow
![](/img/BLE_Bus_Notifier/SceneFlow.png)    

<center><b>Scene Flow Pic</b></center>

Scenes' transactions is like above. let me write details scene by scenes.<br><br>

---

## Scenes

| <img src="/img/BLE_Bus_Notifier/Scene0_rangingBeacon.png" width="200">    | <img src="/img/BLE_Bus_Notifier/Scene1_beaconDetected.png"  width="200">    | <img src="/img/BLE_Bus_Notifier/Scene2_destinationSetting.png"  width="200">    |
|=====
| <center> <a href="./#scene-0---beacon-ranging-scene">Scene 0</a> </center>   | <center> <a href="./#scene-1---bus-detail-scene--destination-not-set">Scene 1 </a> </center>    | <center> <a href="./#scene-2---bus-detail-scene--destination-setting"> Scene </a> 2</center>
{: rules="groups"}

### Scene 0 - Beacon Ranging Scene
 First, 'Beacon Ranging Scene'. in this scene, app tries to detect bus' beacons. for find appropriate beacon, we use fixed `UUID`. if app detects **only one** suitable `UUID`, app automatically goes to Next Scene. when app finds **More than one** proper `UUID`, app shows list with Bus Number and its current location.(like above screenshot) I implement bus' number with iBeacon's `Major` value and bus' location with `Minor` value.<br><br>


### Scene 1 - Bus Detail Scene ; Destination not set
 When app listens proper bus' beacon, app's beacon Listener add Major value to listen only one beacon. (so, UUID and Major value. e.g, *listening for beacon* `UUID`: **ABCDEFGH - EEEE - EEEE - EEEE - ABCDEFGHIJKL**, `Major` : **28**.) and app listens beacon's 'Minor' value changes. that means bus' location. I use euclidean distance for get where current bus' stop is. (this is not implemented in App part, but in Raspberry Pi - beacon part. not in repository. Sorry!) when Raspberry Pi determines that bus is at next stop, it changes beacon's `Minor` value. and app receives that and shows it.<br>
 App user have to select destination for get push notification. user can select destination with clicking '목적지 설정' button. it shows sidebar menu.<br><br>


### Scene 2 - Bus Detail Scene ; Destination setting
 Sidebar menu for set destination. it shows favorite destination, and can select destination of course. app determines Favorite stop with your destination set history. dest set history implements with [AsyncStorage](http://facebook.github.io/react-native/docs/asyncstorage.html)(SQLite, local DB storage). with key`(bus' Number, bus stop)` - value`(destination set counts)` pair. When user set destination, app starts count remaining stops.<br><br>


 | <img src="/img/BLE_Bus_Notifier/Scene3_destinationIsSet.png" width="300">    | <img src="/img/BLE_Bus_Notifier/Scene4_BackgroundPush1.png"  width="300">    |
 |=====
 | <center> <a href="./#scene-3---bus-detail-scene--destination-is-set">Scene 3</a> </center>   | <center> <a href="./#scene-4---background-push--destination-is-next-stop"> Scene 4 </a></center>
 {: rules="groups"}


### Scene 3 - Bus Detail Scene ; Destination is set
 App shows how many stops remain to destination. app refreshes [state](http://facebook.github.io/react-native/docs/state.html) with received beacon advertisement and `refreshState` function. if remaining stops is lesser then two, app sends push notification that remaining stops is few.<br><br>

### Scene 4 - Background Push ; destination is next stop!
 App sends background push notification like above.(Scene 4, push message - *destination is next stop!*)<br><br>


 | <img src="/img/BLE_Bus_Notifier/Scene5_BackgroundPush_arrived.png" width="300">    | <img src="/img/BLE_Bus_Notifier/Scene6_ForegroundAlert.png"  width="300">    |
 |=====
 | <center> <a href="./#scene-5---background-push--arrived-to-destination">Scene 5</a> </center>   | <center> <a href="./#scene-6---foreground-alert--arrived-to-destination"> Scene 6 </a> </center>
 {: rules="groups"}


### Scene 5 - Background Push ; arrived to destination!
App sends background push notification like above.(Scene 5, push message - *Arrived to destination!*)<br><br>


### Scene 6 - Foreground Alert ; arrived to destination!
 When app is on foreground, app sends alert message.(Scene 6, alert message - *Arrived to destination!* )<br><br>
