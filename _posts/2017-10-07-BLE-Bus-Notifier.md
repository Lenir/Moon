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
feature: /assets/img/BLE_Bus_Notifier/SceneFlow.png
comments: true
---
## Project Synopsis
This project's goal is build service that provides bus location which user want to be notified, and notify it to user via push notification.<br>
이 프로젝트의 목표는 유저가 원하는 버스 위치를 알려주고, 그걸 푸시 알림으로 알려주는 서비스를 만드는 것입니다.<br><br>

---

## Used/Referenced
1. [**React native**](http://facebook.github.io/react-native/) - facebook<br>
facebook's mobile app dev framework. good for fast mobile app realization, and good performance!(compare with other 'hybrid app')<br>
페이스북의 RN. 빠른 앱 구현을 위해서 좋은 프레임워크입니다. 다른 '하이브리드 앱'에 비해 성능도 월등합니다!(실제로 RN은 하이브리드 앱은 아닙니다.)
   1. [**React native Korean Tutorial**](https://www.gitbook.com/book/g6ling/react-native-tutorial-korean)<br>facebook's React native Doc is good enough, but this Tutorial doc is more comfortable for developer who uses korean in native.<br>
    페이스북의 공식 RN문서는 충분히 좋습니다..만 한글로 되어 있는 문서가 있으면 더 편하겠죠!
   2. [**React native router flux**](https://github.com/aksonov/react-native-router-flux)<br>
   Scene control<br>
   장면 전환 라우터.
   3. [**React native beacons manager**](https://github.com/MacKentoch/react-native-beacons-manager)<br>
   Beacon Listeners<br>
   비콘 리스너
   4. [**React native background timer**](https://github.com/ocetnik/react-native-background-timer)<br>Background timer for push notification<br>
   푸시 알림을 위한 백그라운드 타이머
   5. [**React native push notification**](https://github.com/zo0r/react-native-push-notification)<br>mobile native(iOS, Android) push notification library<br>
   RN을 위한 모바일 네이티브(iOS, Android) 푸시알림 라이브러리
   6. [**React native Elements**](https://github.com/react-native-training/react-native-elements)<br>Awesome UI Library!<br>
   심플하면서 좋은 UI 라이브러리
2. **Raspberry Pi** - School provides to us. old version.(no Wifi, no bluetooth, no gps.)<br>
학교 랩에서 지원받았습니다. 초기 버전이라 와이파이와 블루투스가 안되는 버전입니다.
   1. **GPS module**<br>with external antenna.<br>
   외부 안테나와 함께 사용.
   2. **Bluetooth Low Energy(BLE) module**<br>beacon broadcasting. we use iBeacon standard.<br>
   라즈베리 파이에 블루투스 모듈이 없어서 따로 장착하였습니다. 비콘 브로드캐스팅용.<br><br>

---

## Scene Flow
![SceneFlow](/assets/img/BLE_Bus_Notifier/SceneFlow.png)    

<center><b>Scene Flow Pic</b></center>
<center><b>장면 구성도</b></center>

Scenes' transactions is like above. let me write details scene by scenes.<br><br>
장면 전환과 그에 관여하는 함수들은 위의 그림과 같습니다. 밑에서 각 장면에 대한 설명을 보실 수 있습니다.<br><br>

---

## Scenes - Detail

<figure class="third">
	<img src="/assets/img/BLE_Bus_Notifier/Scene0_rangingBeacon.png">
	<img src="/assets/img/BLE_Bus_Notifier/Scene1_beaconDetected.png">
	<img src="/assets/img/BLE_Bus_Notifier/Scene2_destinationSetting.png">
	<center><figcaption>Scene 0, Scene 1, Scene 2</figcaption></center>
</figure>
### Scene 0 - Beacon Ranging Scene
 First, 'Beacon Ranging Scene'. in this scene, app tries to detect bus' beacons. for find appropriate beacon, we use fixed `UUID`. if app detects **only one** suitable `UUID`, app automatically goes to Next Scene. when app finds **More than one** proper `UUID`, app shows list with Bus Number and its current location.(like above screenshot) I implement bus' number with iBeacon's `Major` value and bus' location with `Minor` value.<br><br>
 첫번째로, '비콘 탐색 장면'입니다. 이 장면에서 앱은 버스의 비콘을 탐색합니다. 적절한 비콘을 찾기 위해서, 이 서비스에서는 고정된 `UUID`값을 사용합니다. 만약 앱이 **단 한개** 의 적절한 `UUID`를 가진 비콘을 찾았다면, 바로 다음 장면으로 넘어갑니다. 만약 앱이 **두개 이상** 의 적절한 `UUID`를 가진 비콘을 찾았다면, 앱은 탐지된 버스의 번호와 위치를 리스트로 보여줍니다. (위의 스크린샷처럼 말입니다.) 저는 버스의 번호와 현 정류장을 구하기 위해 iBeacon 프레임의 `Major`값과 `Minor`값을 사용했습니다.<br><br>

### Scene 1 - Bus Detail Scene ; Destination not set
 When app listens proper bus' beacon, app's beacon Listener add Major value to listen only one beacon. (so, UUID and Major value. e.g, *listening for beacon* `UUID`: **ABCDEFGH - EEEE - EEEE - EEEE - ABCDEFGHIJKL**, `Major` : **28**.) and app listens beacon's 'Minor' value changes. that means bus' location. I use euclidean distance for get where current bus' stop is. (this is not implemented in App part, but in Raspberry Pi - beacon part. not in repository. Sorry!) when Raspberry Pi determines that bus is at next stop, it changes beacon's `Minor` value. and app receives that and shows it.<br>
 App user have to select destination for get push notification. user can select destination with clicking '목적지 설정' button. it shows sidebar menu.<br><br>
 앱이 버스의 비콘을 찾으면, 앱의 비콘 리스너는 리스너의 파라메터에 Major값을 추가하여 해당 비콘만 탐색하도록 합니다. (즉, UUID와 Major 값이 필터링용으로 쓰입니다. 예를 들어 `UUID`: **ABCDEFGH - EEEE - EEEE - EEEE - ABCDEFGHIJKL**, `Major` : **28** 인 비콘을 *리스닝* 합니다. ) 그리고 만약 버스의 위치가 바뀌면, 라즈베리파이에서 비콘의 `Minor`값을 바꿉니다. Minor값, 즉 버스의 현 정류장 위치를 파악하기 위해 유클리드 거리 공식을 사용하였습니다.(반경 거리 측정. 이 부분은 라즈베리 파이 내부에서 구현하였습니다. 즉, 제 담당이 아니었죠. Sorry!)<br>
 앱 사용자는 푸시 알림을 받기 위해 목적지를 설정해야 합니다. 사용자는 '목적지 설정'버튼을 클릭하여 목적지를 설정할 수 있습니다. 누르면 사이드바 메뉴가 뜨죠. <br><br>

### Scene 2 - Bus Detail Scene ; Destination setting
 Sidebar menu for set destination. it shows favorite destination, and can select destination of course. app determines Favorite stop with your destination set history. dest set history implements with [AsyncStorage](http://facebook.github.io/react-native/docs/asyncstorage.html)(SQLite, local DB storage). with key`(bus' Number, bus stop)` - value`(destination set counts)` pair. When user set destination, app starts count remaining stops.<br><br>
 목적지 설정을 위한 사이드바 메뉴입니다. 이 사이드바 메뉴에서는 목적지를 설정하고, 사용자가 자주 가는 목적지를 보여줍니다. 자주 가는 정류장은 사용자가 목적지로 설정한 기록을 통해 결정됩니다. 이 기록은 RN의 [AsyncStorage](http://facebook.github.io/react-native/docs/asyncstorage.html)(SQLite입니다. 로컬 데이터베이스라고 보시면 됩니다.)를 통해 구현하였습니다. 이는 키`(버스 번호, 버스 정류장)`; 쌍(튜플) -  값`(목적지로 설정한 횟수)`으로 이루어져 있습니다. 즉, 목적지로 설정할 때 마다 1씩 올라가게 되어 있죠. 목적지를 설정하면 앱은 목적지까지 남은 정류장을 카운팅하기 시작합니다.<br><br>
<figure class="half">
  <img src="/assets/img/BLE_Bus_Notifier/Scene3_destinationIsSet.png">
  <img src="/assets/img/BLE_Bus_Notifier/Scene4_BackgroundPush1.png">
  <center><figcaption>Scene 3, Scene 4</figcaption></center>
</figure>
### Scene 3 - Bus Detail Scene ; Destination is set
 App shows how many stops remain to destination. app refreshes [state](http://facebook.github.io/react-native/docs/state.html) with received beacon advertisement and `refreshState` function. if remaining stops is lesser then two, app sends push notification that remaining stops is few.<br><br>
 목적지가 정해졌다면 앱은 목적지까지 얼마나 남았는지 보여줍니다. 앱은 `refreshState`함수를 통해 [state](http://facebook.github.io/react-native/docs/state.html)를 갱신합니다. 만약 목적지까지 남은 정류장이 두 정류장 이하라면, 앱은 남은 정류장이 몇 되지 않는다고 푸시알림을 보냅니다.<br><br>

### Scene 4 - Background Push ; destination is next stop!
 App sends background push notification like above.(Scene 4, push message - *destination is next stop!*)<br><br>
 위 스크린샷(장면 4, 푸시 메세지 : *다음 정류장이 목적지 입니다!*) 처럼 푸시 알림을 보냅니다.<br><br>

 <figure class="half">
   <img src="/assets/img/BLE_Bus_Notifier/Scene5_BackgroundPush_arrived.png">
   <img src="/assets/img/BLE_Bus_Notifier/Scene6_ForegroundAlert.png">
   <center><figcaption>Scene 5, Scene 6</figcaption></center>
 </figure>

### Scene 5 - Background Push ; arrived to destination!
App sends background push notification like above.(Scene 5, push message - *Arrived to destination!*)<br><br>
앱이 만약 백그라운드에서 돌아간다면 다음과 같이 백그라운드 푸시를 보냅니다.(장면 5, 푸시 메세지 : *목적지에 도착하였습니다!*) <br><br>

### Scene 6 - Foreground Alert ; arrived to destination!
 When app is on foreground, app sends alert message.(Scene 6, alert message - *Arrived to destination!* )<br><br>
 앱이 만약 포어그라운드에서 돌아간다면 다음과 같이 Alert를 보냅니다.(장면 6, Alert 메세지 : *목적지에 도착하였습니다!*) <br><br>
