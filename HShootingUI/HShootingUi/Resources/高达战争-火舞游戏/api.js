/**
 * Copyright 2014 51h5.com All rights reserved.
 */
!function(e,t){function n(e){var t=$t[e],n=Array.prototype.slice.call(arguments,1);if(t){t=t.slice(0);for(var o=0,r=t.length;r>o;o++)t[o].apply(At,n)}}function o(){if(!Nt&&!Ut){Ut=!0,Bt.gameId=N("gameid"),Bt.appBanner=ut[dt]&&ut[dt][3]?"no":N("appbanner"),At.get("init",function(){Ut=!1,jt=localStorage.getItem(Wt+"guid");var e=N("key");return e&&(Ct=e,Qt=Ct+"_"),Ct?void At.get("bt",function(e){return e?(Ot=e.token,jt=e.guid,localStorage.setItem(Wt+"guid",jt),void At.get("vt",function(e){return e?(Lt=e,Nt=!0,a(),Rt.forEach(function(e){c.apply(null,e)}),void(Rt=null)):void n("error",{type:"init",code:102})})):void n("error",{type:"init",code:101})}):void n("error",{type:"init",code:100})}),Bt.channelLogo=ut[dt]&&ut[dt][0],Bt.channelAloneLogo=Bt.channelLogo&&ut[dt][1];var e=N("splashscreen");return e&&(Ft=parseInt(e,10)||0),Ft&&At.splashscreen(Ft+(Bt.channelAloneLogo?qt:0)),"function"==typeof onHoowuReady&&onHoowuReady(),At}}function r(){if(!At.is("wechat")&&!("no"===(N("toolbar")||"").toLowerCase()||ut[dt]&&ut[dt][2])){var e=M(Gt);if(!e){var t=[Gt+" {text-shadow:none;font-family:'Microsoft Yahei', Arial, 'Helvetica Neue', sans-serif;-webkit-font-smoothing: antialiased;z-index: 99990;text-align: left;height: 0;width: 0;font-size: 13px;}",Gt+" * {padding: 0; margin: 0; -webkit-touch-callout: none; -webkit-user-select: none; -khtml-user-select: none; -moz-user-select: none; -ms-user-select: none; user-select: none;}",Gt+" .hw-bar {width: 170px; box-sizing: border-box; position: fixed; z-index: 99990; top: 10px; left: -190px; background-color: #FFF; box-shadow: 0 0 3px rgba(0,0,0,0.3);transition-property: left; transition-timing-function: ease-in; transition-duration: .3s;}",Gt+" .hw-bar.hw-bar-expand {left:0;}",Gt+" .hw-bar header {width: 100%; height: 36px; text-align: center; color: #FFF; background-color: #1399d2;}",Gt+" .hw-bar h4 {display: inline; line-height: 38px;}",Gt+" .hw-bar .hw-clip {display: block; position: absolute; z-index: 3000; height: 38px; width: 60px; top: 0; right: -60px; background-color: transparent;}",Gt+" .hw-bar .hw-clip-btn {height: 36px; background-color: #1399d2; box-shadow: 3px 0 3px rgba(0,0,0,0.2); position: relative; transition-property: width; transition-timing-function: ease-in; transition-duration: .3s;}",Gt+" .hw-bar .hw-clip-btn img {height: 30px; position: absolute; top: 3px; right: 5px;}",Gt+" .hw-bar nav ul {list-style: none; text-align: center;}",Gt+" .hw-bar nav a {font-size: 14px; line-height: 34px; text-decoration: none; display: block; font-weight: 700; color: #666; border-top: 1px solid #E5E5E5;}",Gt+" .hw-bar nav em {font-style: normal; color: #0080ff; margin: 0 2px;}",Gt+" .hw-bar nav strong {color: #f0404f;}",Gt+" .hw-bar nav .hw-btn-app {font-size: 12px; background: #F7F6F6;}",Gt+" .hw-bar nav .hw-btn-resume {font-size: 18px; font-weight: 900; color: #fff; background: #1399d2;}"];y(t.join("")),e=J.createElement("div"),e.id=Gt.slice(1),e.innerHTML=['<div id="hw-bar" class="hw-bar">',"<header>","<h4>火舞游戏，为未来而生</h4>",'<div class="hw-clip">','<div class="hw-clip-btn"><img src="'+xt+'/images/home/logo200.png"></div>',"</div>","</header>","<nav>","<ul>",At.env.app?"":'<li><a href="#" class="hw-btn-app" data-action="app">安装<strong>火舞APP</strong>，体验精品游戏</a></li>',At.env.wechat?'<li><a href="#" data-action="share">挑战好友</a></li>':"",'<li><a href="#" data-action="more">更多游戏</a></li>','<li><a href="#" class="hw-btn-resume" data-action="close">返回游戏</a></li>',"</ul>","</nav>","</div>"].join(" "),e.addEventListener(tt,R),e.addEventListener(ot,R),M("header",e).addEventListener(tt,function(){U("toolbar","click","toggle"),i()}),M("nav",e).addEventListener(nt,function(e){var t=e.target.getAttribute("data-action");t&&(e.preventDefault(),U("toolbar","click",t)),"app"===t?At.download():"share"===t?(At.share(),i(!1)):"follow"===t?At.follow():"more"===t?At.more():"close"===t&&i(!1)}),M("body").appendChild(e),Bt.toolbarExpand=!1}return e}}function i(e){var t="boolean"===k(e)?e:!Bt.toolbarExpand;t!==Bt.toolbarExpand&&(Bt.toolbarExpand=t,M(Gt+" .hw-bar").className="hw-bar"+(t?" hw-bar-expand":""))}function a(){var e=M(Kt);e||(e=J.createElement("iframe"),e.width=e.height=1,e.style.display="none",M("head").appendChild(e)),e.src=D(St+"/apis-sso.html",{id:jt,t:Ct,bt:Ot,vt:Lt,_:Date.now()})}function s(e,t,n){new Image(1,1).src=D(kt+"/tj.gif",T({act:e,aop:t,id:jt||"",t:Ct||""},n||{}))}function c(e,t,n,o){var r=zt[t];if(r&&!(0===r&Pt[e])){if(!Nt&&"init"!==t&&"bt"!==t&&"vt"!==t)return void Rt.push(Array.prototype.slice.call(arguments));E(n)&&(o=n,n=null);var i=Dt[t];if(i){try{i.abort()}catch(a){}i=null,delete Dt[t]}Dt[t]=w(et,l(t,e),n,o)}}function l(e,t){return St+Et+(t===Z?"get":"set")+e+".html"}function u(e){return e.charAt(0).toUpperCase()+e.slice(1)}function d(e){var t,n=Bt.share.descCustom;e&&n&&(e.hasOwnProperty("level")&&(t=(t||n).replace(/\{l\}/g,e.level||1)),e.hasOwnProperty("score")&&(t=(t||n).replace(/\{s\}/g,e.score||0)),e.hasOwnProperty("time")&&(t=(t||n).replace(/\{t\}/g,e.time||0)),e.hasOwnProperty("title")&&(t=(t||n).replace(/\{tt\}/g,e.title||""))),t&&At.setShare({desc:t})}function p(e){var t=null,o=h(),r="none"!==o.style.display;if("boolean"===k(e)?e!==r&&(t=e?1:0):t=r?0:1,null!==t){o.style.display=t?"block":"none",n("splashscreen."+(t?"show":"hide"));var i=A(".inner",o);i[0].style.display=t?"block":"none",Bt.channelAloneLogo&&t&&i.length>1&&(clearTimeout(Zt),Zt=setTimeout(function(){i[1].style.display="block",i[0].parentNode.removeChild(i[0]),i=null},qt))}}function h(){var e=M(en);if(!e){var t=N("author");t&&(t=t.replace(/</g,"&lt;").replace(/>/g,"&gt;"));var n=[en+" {position:fixed;left:0;top:0;z-index:9947483646;width:100%;height:100%;box-sizing:border-box;color:#fff;text-shadow:none;font-family:'Microsoft Yahei', Arial, 'Helvetica Neue', sans-serif;-webkit-font-smoothing: antialiased;}",en+" .inner {display:none;position:relative;top:0;width:100%;height:100%;padding-top:80px;pointer-events:none;background: #fff;}",en+" .inner[data-ui~=day] {background: #167de6;}",en+" .inner[data-ui~=night] {background: #2c2a2a;}",en+" .inner[data-ui~=alone] {padding-top:0;}",en+" .inner[data-ui~=alone] img {width: auto;height: auto;position: absolute;top: 40%;left: 50%;margin:-100px auto auto -130px;}",en+" img {display:block;margin:10px auto 30px;height:80px;width:auto;}",en+" p {font-size:16px;line-height:24px;text-align:center;margin:10px auto;padding:0 10px;}",en+" .hw_info {font-size: 12px;color: rgba(255,255,255,.7);}",en+" .progress {height:20px;overflow:hidden;margin: 5px 10px;background-color:#f5f5f5;border-radius:4px;box-sizing:border-box;box-shadow:inset 0 1px 2px rgba(0,0,0,.1);-webkit-box-shadow:inset 0 1px 2px rgba(0,0,0,.1);}",en+" .progress .bar {float:left;min-width:20px;height:100%;line-height:20px;font-size:12px;text-align:center;color:#fff;box-sizing:border-box;background-color:#428bca;box-shadow:inset 0 -1px 0 rgba(0,0,0,.15);-webkit-box-shadow:inset 0 -1px 0 rgba(0,0,0,.15);transition:width .6s ease;-webkit-transition:width .6s ease;-o-transition:width .6s ease;}"];y(n.join("")),e=J.createElement("div"),e.id=en.slice(1),e.style.display="none";var o=(new Date).getHours();o=6>o||o>20?"night":"day",e.innerHTML=Bt.channelLogo&&Bt.channelAloneLogo?['<div class="inner" data-ui="alone">','<img src="'+xt+"/images/home/loading_"+ut[dt][0]+'.png">',"</div>",'<div class="inner" data-ui="alone '+o+'">','<img src="'+xt+'/images/home/loading_hoowu.png" >',"</div>"].join(""):['<div class="inner" data-ui="'+o+'">','<img src="'+xt+'/images/home/logo_wr_220x100_black.png" height="80">',Bt.channelLogo&&!Bt.channelAloneLogo?'<img src="'+xt+"/images/home/logo_"+ut[dt][0]+'.png" height="80">':"",t?"<p><strong>火舞游戏</strong> &bull; <strong>"+t+"</strong> 原创出品</p><p>转载请经过授权，侵权必究</p>":"<p>火舞游戏 &bull; 为未来而生</p>",'<p class="hw_info">游戏载入中...</p>','<div class="progress" style="display:none;"><div class="bar">0%</div></div>',"</div>"].join(""),e.addEventListener(tt,R),e.addEventListener(ot,R),M("body").appendChild(e)}return e}function f(e){var t,o=g(),r="none"!==o.style.display;"boolean"===k(e)?e!==r&&(t=e?"block":"none"):t=r?"none":"block",t&&(o.style.display=t,n("orientation."+("none"===t?"hide":"show")))}function g(){var e=M(on);if(!e){var t=[on+" {position:fixed;left:0;top:0;z-index:9999;width:100%;height:100%;box-sizing:border-box;background:#fff;}",on+" .inner {width:100%;height:100%;padding-top:200px;pointer-events:none;}",on+" .tip {position:absolute;top:80px;left:50%;margin-left:-64px;width:128px;z-index:9999;}",on+" p {color:#4a87ee;font-size:16px;line-height:24px;text-align:center;margin:10px auto;padding:0 10px;}"];y(t.join("")),e=J.createElement("div"),e.id=on.slice(1),e.style.display="none",e.innerHTML=['<div class="inner">','<img src="'+xt+'/images/orientation.gif" class="tip">',"<p>请旋转手机屏幕，以达到最佳效果</p>","</div>"].join(" "),e.addEventListener(tt,R),e.addEventListener(ot,R),M("body").appendChild(e)}return e}function m(){clearTimeout(an),an=setTimeout(function(){var t=!0,o=e.orientation;if(0===o||180===o)t=!0;else if(-90===o||90===o)t=!1;else{var r=B();t=r.h>r.w}null===tn?tn=t:tn!==t&&(tn=t,n("orientation",t)),"boolean"==typeof nn&&f(t!==nn)},rn)}function v(t,o){t&&o&&!Bt.banner&&(S(o)&&(o=M("#"+o)),J.documentElement.contains(o)&&((e.BAIDU_DUP=e.BAIDU_DUP||[]).push(["fillAsync",t,o]),Bt.banner=!0,n("banner.set")))}function w(t,n,o,r){var i=new XMLHttpRequest;return t===Z&&o&&(n=D(n,o),o=null),i.open(t,n,!0),Ct&&i.setRequestHeader("X-KEY",Ct),(Ot||Lt)&&i.setRequestHeader("X-TOKEN",Lt||Ot),jt&&i.setRequestHeader("X-GUID",jt),t===et&&i.setRequestHeader("Content-Type","application/x-www-form-urlencoded"),r&&(i.onerror=i.onabort=function(){b(i),r(null,500,i)},i.onload=function(){b(i);var t=i.status;if(t>=200&&300>t||304==t){var n,o=i.responseText;try{n=JSON.parse(o)}catch(a){e[Tt](o)}if(n&&n.url)return void(location.href=n.url);n&&1===n.status?r(n.data||"",n.status,i):r(null,n.status,i)}else r(null,t,i)}),i.send(e.FormData&&o instanceof FormData?o:S(o)?o:z(o)),i}function b(e){e.onload=e.onabort=e.onerror=e.ontimeout=null}function y(e,t){var n;t=t||J,n=t.createElement("style"),n.type="text/css",t.getElementsByTagName("head")[0].appendChild(n),n.styleSheet?n.styleSheet.cssText=e:n.appendChild(t.createTextNode(e))}function x(e,t){var n;t=t||J,n=t.createElement("script"),n.type="text/javascript",n.async="async",n.src=e,t.getElementsByTagName("head")[0].appendChild(n)}function k(e){return null==e?String(e):Mt[Object.prototype.toString.call(e)]||"object"}function S(e){return"string"===k(e)}function E(e){return"function"===k(e)}function _(e){return"object"===k(e)&&Object.getPrototypeOf(e)===Object.prototype}function I(e,t){Object.keys(e).forEach(function(n){t(n,e[n])})}function T(e,t){return I(t,function(t,n){e[t]=n}),e}function M(e,t){return S(e)?(t=t||J,t.querySelector(e)):e}function A(e,t){return S(e)?(t=t||J,[].slice.call(t.querySelectorAll(e),0)):e}function C(e){return"string"==typeof e&&""!==e}function O(e){return C(e)}function L(t){var n=e.location.search.substr(1).match(new RegExp("(^|&)"+t+"=([^&]*)(&|$)"));return n?decodeURIComponent(n[2]):null}function j(e,t){if(C(e)){var n=String(J.cookie).match(new RegExp("(?:^| )"+e+"(?:(?:=([^;]*))|;|$)"));if(n)return(n=n[1])?t?decodeURIComponent(n):n:""}return null}function P(e,t){return t=t||{},j(O(e)?e:"",!t.raw)}function z(e){var t=[];return I(e||{},function(e,n){Array.isArray(n)||(n=[n]),n.forEach(function(n){t.push(e+"="+encodeURIComponent(n))})}),t.join("&")}function D(e,t){S(t)||(t=z(t)),e=e.split("#");var n=e[1];return e=e[0],t&&(e+=e.indexOf("?")>=0?"&":"?",e+=t+(n?"#"+n:"")),e}function R(e){e&&(e.preventDefault(),e.stopPropagation())}function B(){return{w:e.innerWidth,h:e.innerHeight}}function N(e,t){var n=M('meta[name="x-'+e+'"]');return n?(n.getAttribute(t?"data-"+t:"content")||"").trim():null}function U(t){var n=[V+"trackEvent",t].concat(Array.prototype.slice.call(arguments,1).map(function(e){return t+V+e}));["hmt","czc"].forEach(function(t){var o=e[V+t];o&&o.push(n)})}function H(e,t){e=e.split("."),t=t.split(".");for(var n=0,o=Math.max(e.length,t.length);o>n;n++)if(e[n]=parseInt(e[n],10)||0,t[n]=parseInt(t[n],10)||0,e[n]!==t[n])return e[n]>t[n]?1:-1;return 0}for(var F=":",q="/",W=".",Q="-",V="_",Y="1",G="5",K=[],X=97;122>X;X++)K.push(String.fromCharCode(X));var J=e.document,Z="GET",et="POST",tt="touchstart",nt="touchend",ot="mousedown",rt=location.protocol,it=location.hostname,at=location.pathname,st=e.navigator.userAgent,ct=K[7]+K[19]+K[19]+K[15]+F+q+q,lt=W+K[2]+K[14]+K[12],ut={1003:["ishanku"],1004:["uc",!1,!0,!0],1005:["",!1,!1,!0],1006:["",!1,!1,!0],1007:[],1008:[],1009:[],1010:[],1011:"",1012:["chetuobang"],1013:["youxiduo"],1014:["",!1,!0,!0],1015:["",!1,!0,!0],1016:["weibo",!0,!0,!0],1017:[]},dt=0|L("f"),pt=/(?:51h5|wanh5|h5hero|h5wenhua|h5jiaoyu|h5jiaju)\.com$/.test(it),ht="i1.wanh5.com"===it||/(?:\d+\.){3}\d+/.test(it)||/^dev\./.test(it),ft=ht?K[3]+K[4]+K[21]+W:"",gt=ct+ft+K[22]+K[22]+K[22]+W+G+Y+K[7]+G+lt,mt=gt+q+K[22]+K[23],vt=gt+q+K[0]+K[15]+K[15]+Q+K[3]+K[14]+K[22]+K[13]+K[11]+K[14]+K[0]+K[3]+W+K[7]+K[19]+K[12]+K[11],wt=gt+q+K[22]+K[23]+Q+K[3]+K[14]+K[22]+K[13]+W+K[7]+K[19]+K[12]+K[11],bt="http://mp.weixin.qq.com/s?__biz=MzAwODE2MzEwMQ==&mid=202092460&idx=1&sn=5a901ce32da0c3f7bdb8230e5993beb3#rd",yt=ct+ft+K[17]+K[0]+K[13]+K[10]+W+G+Y+K[7]+G+lt,xt=ct+ft+K[18]+K[19]+K[0]+K[19]+K[8]+K[2]+W+K[22]+K[0]+K[13]+K[7]+G+lt,kt=ct+"tongji"+W+G+Y+K[7]+G+lt,St=ct+ft+K[0]+K[15]+K[8]+W+G+Y+K[7]+G+lt,Et=q+K[0]+K[15]+K[8]+K[18]+Q,_t=rt+"//"+location.host,It=_t+at.replace(/\/([^\/]+\.\w+)$/,"/").replace(/\w+$/,"$1/"),Tt=K[4]+K[21]+K[0]+K[11],Mt={};"Boolean Number String Function Array Date RegExp Object Error".split(" ").forEach(function(e){Mt["[object "+e+"]"]=e.toLowerCase()});var At=e.ih5game={};At.ver="1.4",At.channel=dt;var Ct,Ot,Lt,jt,Pt={GET:1,SET:2},zt={init:1,bt:1,vt:1,ui:1,gv:1,jf:3,ph:1,ok:1,data:3,title:1,tc:2,guc:3,gpd:3,dtc:1,grlg:1},Dt={},Rt=[],Bt={gameId:null,bestScore:0,nick:"火舞玩家",share:{img:N("share-icon"),title:N("share-title"),titleCustom:N("share-title","custom"),desc:N("share-desc"),descCustom:N("share-desc","custom"),link:N("share")}},Nt=!1,Ut=!1,Ht=!1,Ft=3e3,qt=1500,Wt="51h5_",Qt=Wt,Vt="51h5_user",Yt="wx_user",$t={};At.on=function(e,t){return $t[e]=$t[e]||[],$t[e].push(t),At},At.once=function(e,t){function n(){At.off(e,n),t.apply(this,arguments)}return n.listener=t,At.on(e,n),At},At.off=function(e,t){if(0===arguments.length)return $t={},At;var n=$t[e];if(!n)return At;if(1===arguments.length)return delete $t[e],At;for(var o,r=0;r<n.length;r++)if(o=n[r],o===t||o.listener===t){n.splice(r,1);break}return At},At.env={},At.is=function(e){return e=e.toLowerCase(),At.env.hasOwnProperty(e)&&At.env[e]?!0:!1},function(e){var t=(st.match(/Web[kK]it[\/]{0,1}([\d.]+)/),st.match(/(Android);?[\s\/]+([\d.]+)?/)),n=(!!st.match(/\(Macintosh\; Intel /),st.match(/(iPad).*OS\s([\d_]+)/)),o=st.match(/(iPod)(.*OS\s([\d_]+))?/),r=!n&&st.match(/(iPhone\sOS)\s([\d_]+)/),i=st.match(/(webOS|hpwOS)[\s\/]([\d.]+)/),a=st.match(/Windows Phone ([\d.]+)/),s=(i&&st.match(/TouchPad/),st.match(/Kindle\/([\d.]+)/),st.match(/Silk\/([\d._]+)/),st.match(/(BlackBerry).*Version\/([\d.]+)/)),c=st.match(/(BB10).*Version\/([\d.]+)/),l=(st.match(/(RIM\sTablet\sOS)\s([\d.]+)/),st.match(/PlayBook/)),u=st.match(/Chrome\/([\d.]+)/)||st.match(/CriOS\/([\d.]+)/),d=st.match(/Firefox\/([\d.]+)/),p=st.match(/MSIE\s([\d.]+)/)||st.match(/Trident\/[\d](?=[^\?]+).*rv:([0-9.].)/),h=!u&&st.match(/(iPhone|iPod|iPad).*AppleWebKit(?!.*Safari)/),f=(h||st.match(/Version\/([\d.]+)([^S](Safari)|[^M]*(Mobile)[^S]*(Safari))/),st.match(/MicroMessenger\/([\d.]+)/)),g=(st.match(/baiduboxapp\/[^\/]+\/([\d.]+)_/)||st.match(/baiduboxapp\/([\d.]+)/)||st.match(/BaiduHD\/([\d.]+)/)||st.match(/FlyFlow\/([\d.]+)/)||st.match(/baidubrowser\/([\d.]+)/),st.match(/MQQBrowser\/([\d.]+)/)||st.match(/QQ\/([\d.]+)/),st.match(/UCBrowser\/([\d.]+)/),st.match(/SogouMobileBrowser\/([\d.]+)/),t&&st.match(/MiuiBrowser\/([\d.]+)/),st.match(/LBKIT/),st.match(/Mercury\/([\d.]+)/),st.match(/Html5Plus\/([\d.]+)/)),m=st.match(/__weibo__([\d.]+)__/);m&&(e.weibo=m[1]),f&&(e.wechat=f[1]),a&&(e.wp=a[1]),t&&(e.android=t[2]),n&&(e.ipad=n[2].replace(/_/g,".")),o&&(e.ipod=o[3].replace(/_/g,".")||null),r&&(e.iphone=r[2].replace(/_/g,".")),(e.ipod||e.iphone||e.ipad)&&(e.ios=!0),g&&(e.app=g[1]),st.match(/mso_app/i)&&(e.mso="1.0"),/\s+weico/i.test(st)&&(e.weico="1.0"),e.tablet=!!(n||l||t&&!st.match(/Mobile/)||d&&st.match(/Tablet/)||p&&!st.match(/Phone/)&&st.match(/Touch/)),e.phone=!(e.tablet||e.ipod||!(t||r||i||s||c||u&&st.match(/Android/)||u&&st.match(/CriOS\/([\d.]+)/)||d&&st.match(/Mobile/)||p&&st.match(/Touch/)))}(At.env),At.storage={driver:"localStorage"in e?localStorage:null,get:function(e){return this.driver?this.driver.getItem(Qt+e):null},set:function(e,t,n){!this.driver||!e||n&&null!==this.get(e)||this.driver.setItem(Qt+e,t)},remove:function(e){this.driver&&e&&null!==this.get(e)&&this.driver.removeItem(Qt+e)},clear:function(){if(this.driver)for(var e in this.driver)0===e.indexOf(Qt)&&this.driver.removeItem(e)}},e.addEventListener("storage",function(e){if(Ct){var t=e.key;if(t&&0===t.indexOf(Qt)){var o={key:t.slice(Qt.length),from:e.oldValue,to:e.newValue,time:e.timeStamp,url:e.url};null===o.from?n("storage.add",{key:o.key,value:o.to,time:o.time,url:o.url}):null===o.to?n("storage.remove",{key:o.key,time:o.time,url:o.url}):n("storage.change",o),n("storage",o)}}}),At.config=function(e,t){if(_(e))for(var n in e)At.config(n,e[n]);else"nickName"===e&&t&&(Bt.nick=t);return At},At.init=function(){},At.ssoFinish=function(e){At.getUser(function(e){e&&e.name&&(Bt.nick=e.name)}),n("sso",e),n("init")},At.ready=function(e){return Ht?e&&e():At.once("ready",e),At},/complete|loaded|interactive/.test(J.readyState)&&J.body?Ht=!0:J.addEventListener("DOMContentLoaded",function(){Ht=!0,n("ready")},!1);var Gt="#hw-toolbar";At.ready(r);var Kt="#ih5game_sso";At.get=function(e,t,n){var o=At[Z.toLowerCase()+u(e)];return o?o(t,n):c(Z,e,t,n),At},At.set=function(e,t,n){var o=At[et.toLowerCase()+u(e)];return o?o(t,n):c(et,e,t,n),At};var Xt=[0,0,0,0,0,0,0];At.start=function(e){return Xt[0]||(Xt[0]=Date.now()),Xt[1]=Date.now(),Xt[2]=Xt[3]=0,s("game","start",e),n("status.start",e),At},At.resume=function(e){Xt[2]&&(Xt[2]=0,s("game","resume",e),n("status.resume",e))},At.pause=function(e){return Xt[2]||(Xt[2]=Date.now(),s("game","pause",e),n("status.pause",e)),At},At.stop=function(e){return Xt[3]||(Xt[3]=Date.now(),Xt[1]=Xt[2]=0,s("game","stop",e),n("status.stop",e)),At},At.levelUp=function(e){e=e||{};var t=e.level||1;if(t>Xt[4])Xt[4]=t;else if(!e.force)return At;return s("game","levelup",e),n("status.levelup",e),At},At.complete=function(e){return Xt[5]=Date.now(),s("game","complete",e),n("status.complete",e),At},At.mute=function(e){return Xt[6]||(Xt[6]=1,s("game","mute",e),n("status.mute",e)),At},At.unmute=function(e){return Xt[6]&&(Xt[6]=0,s("game","unmute",e),n("status.unmute",e)),At},At.on("status.stop",d).on("status.levelup",d).on("status.complete",d);At.share=function(){return At},At.env.weico&&(At.share=function(){location.href="weico3://compose?action=present&type=weibo&content="+At.getShare("desc")+"&gameid="+Bt.gameId}),At.hideShare=function(){return At},At.more=function(e){var t=At.env.wechat?mt:gt;return e?t:void(location.href=t)},At.home=function(t){return t?gt:void(e.location.href=gt)},At.follow=function(t){return t?bt:void(e.location.href=bt)},At.download=function(t){var n=At.env.wechat?wt:vt;return t?n:void(e.location.href=n)},At.rank=function(t){var n=yt+"/home/view/key/"+Ct;return t?n:void(e.location.href=n)},At.progress=function(e,t){var o=M(en);if(!o)return At;var r=M(".progress",o);return r?("none"===r.style.display&&(r.style.display="block"),t=S(t)?t.trim():"",t&&(r=M(".hw_info",o))&&(r.innerText=t),e="number"===k(e)?Math.min(100,Math.max(0,e)):-1,e>=0&&(r=M(".progress .bar",o))&&(r.innerText=e+"%",r.style.width=e+"%",n("progress",e,t)),At):At},At.splashscreen=function(e){return Jt=clearTimeout(Jt),"boolean"===k(e)?p(e):e>0?(p(!0),Jt=setTimeout(function(){p(!1)},e)):p(),At};var Jt,Zt,en="#hw_splashscreen",tn=null,nn=null;At.getOrientation=function(){return tn},At.orientationTip=function(e){return"boolean"==typeof e&&(nn=e,m()),At};var on="#hw_orientationtip",rn=At.is("android")?350:100,an=null;At.ready(function(){e.addEventListener("onorientationchange"in e?"orientationchange":"resize",m,!1),m();var t=N("orientation");t&&(t="portrait"===t?1:"landscape"===t?2:parseInt(t,10)||0,t&&At.orientationTip(1===t))}),At.getUser=function(e,t){if(E(e)?(t=e,e=!1):"boolean"!==k(e)&&(e=!1),!t)return At;var o={id:0,name:null,avatar:"http://i1.wanh5.com/avatar/default/1.jpg",gender:0,display:""},r=P(Vt);return r&&(r=decodeURIComponent(r).split("|"),o={id:parseInt(r[0],10)||0,name:decodeURIComponent(r[1])||null,avatar:decodeURIComponent(r[2]),gender:parseInt(r[3],10)||0,display:decodeURIComponent(r[4])||null}),e?c(Z,"ui",function(e,r){null!==e?(o=T(o,e),n("user.get",o)):n("error",{type:"user.get",code:r}),t&&E(t)&&t(o,r)}):(n("user.get",o),t&&E(t)&&t(o)),At},At.getWXUser=function(){var e=P(Yt);if(e)try{e=JSON.parse(decodeURIComponent(e)),n("wxuser.get",e)}catch(t){n("error",{type:"wxuser.get",code:t.message})}return e||null},At.getStat=function(e){return c(Z,"gv",function(t,o){null!==t?n("stat.get",t):n("error",{type:"stat.get",code:o}),e&&E(e)&&e(t,o)}),At},At.getScore=function(e){return c(Z,"jf",function(t,o){null!==t?n("score.get",t):n("error",{type:"score.get",code:o}),e&&E(e)&&e(t,o)}),At},At.setScore=function(e,t,o){if(e=parseFloat(e,10)||0,0>=e||e<=Bt.bestScore)return At;E(t)&&(o=t,t=null);var r={s:e};return Bt.bestScore=e,t=parseFloat(t,10)||0,t>0&&(r.t=t),Bt.nick&&(r.n=Bt.nick),c(et,"jf",r,function(e,t){null!==e?n("score.set",r.s,r.t,r.n):n("error",{type:"score.set",code:t}),o&&E(o)&&o(e,t)}),At},At.setScoreWithName=function(e,t,n,o,r){var i;return _(e)?At.setScoreWithName(e.score,e.time,e.success,e.always,e.tip):((o||e>Bt.bestScore)&&(i=prompt((r||"你获得了%s分, 使用下面名字并通知好友？").replace(/\%s/gi,e),Bt.nick)),i?(Bt.nick=i,At.setScore(e,t,n)):At)},dt&&dt in ut&&(At.setScoreWithName=At.setScore),At.getRank=function(e,t){return E(e)&&(t=e,e=null),c(Z,"ph",{order:S(e)&&"time"===e?"time":"score"},function(e,o){null!==e?n("rank.get",e):n("error",{type:"rank.get",code:o}),t&&E(t)&&t(e,o)}),At},At.getSaveData=function(e){return c(Z,"data",function(t,o){null!==t?n("savedata.get",t):n("error",{type:"savedata.get",code:o}),e&&E(e)&&e(t,o)}),At},At.setSaveData=function(e,t){return S(e)?(e={d:e},c(et,"data",e,function(o,r){null!==o?n("savedata.set",e.d):n("error",{type:"savedata.set",code:r}),t&&E(t)&&t(o,r)}),At):At},At.getData=function(e){return c(Z,"guc",function(t,o){null!==t?n("data.get",t):n("error",{type:"data.get",code:o}),e&&E(e)&&e(t,o)}),At},At.setData=function(e,t){return S(e)?(e={d:e},c(et,"guc",e,function(o,r){null!==o?n("data.set",e.d):n("error",{type:"data.set",code:r}),t&&E(t)&&t(o,r)}),At):At},At.getGameData=function(e,t){return c(Z,"gpd",{p:e},function(o,r){null!==o?n("gamedata.get",e,o):n("error",{type:"gamedata.get",code:r}),t&&E(t)&&t(o,r)}),At},At.setGameData=function(e,t,o){return S(t)?(t={p:e,v:t},c(et,"gpd",t,function(e,r){null!==e?n("gamedata.set",t.p,t.v):n("error",{type:"gamedata.set",code:r}),o&&E(o)&&o(e,r)}),At):At},At.getTitle=function(e){return c(Z,"title",function(t,o){null!==t?n("title.get",t):n("error",{type:"title.get",code:o}),e&&E(e)&&e(t,o)}),At},At.getHotGames=function(e){return c(Z,"grlg",function(t,o){null!==t?n("hotgames.get",t):n("error",{type:"hotgames.get",code:o}),e&&E(e)&&e(t,o)}),At},function(t){function o(e,t){return/^(?:\w+)?:/.test(e)||t&&!/\.(?:png|jpg)$/.test(e)?void 0:(e=e.replace(/^\/+/,""),e=e.replace(/^(\.+\/+)+/,""),It+e)}function r(t,n){l&&pt&&e.wx&&e.wx[t](n)}function i(e,t,o){return l&&d?void r("onMenuShare"+b[e],{title:t.title,desc:t.desc,link:t.link,imgUrl:t.img,trigger:function(){n("share.open",e)},success:function(e){o("success",e)},cancel:function(e){o("cancel",e)},fail:function(e){o("fail",e)}}):void k.push(arguments)}function a(e,t){var o=x[e+"Link"]||x.link;jt&&(o=o+(o.indexOf("?")>=0?"&":"?")+"fu="+encodeURIComponent(jt)),o=o+(o.indexOf("?")>=0?"&":"?")+"ft="+(new Date).getTime(),i(e,{img:x.img,link:o,title:e===m?x.desc:x.title,desc:e===m?x.title:x.desc},function(o){var r={type:e};r[o]=!0,n("share",r),n("share.close"),"cancel"!==o&&s("share",o),t&&E(t)&&t(r)})}function c(t){var o=e.wx;o.config({debug:!1,appId:t.appId,timestamp:t.timestamp,nonceStr:t.nonceStr,signature:t.signature,jsApiList:h}),o.ready(function(){d=!0,a(g),a(m),a(v),a(w),k.forEach(function(e){i.apply(null,e)}),k=[]}),o.error(function(e){n("error",{type:"wx",code:e.errMsg||0})})}var l=!!t.env.wechat,u=!0;l&&t.env.android&&H(t.env.wechat,"6.0.2.58")<0&&(u=!1);var d,p=!l||"no"===N("wxbridge"),h=["checkJsApi","onMenuShareTimeline","onMenuShareAppMessage","onMenuShareQQ","onMenuShareWeibo","hideMenuItems","showMenuItems","hideAllNonBaseMenuItem","showAllNonBaseMenuItem","translateVoice","startRecord","stopRecord","onRecordEnd","playVoice","pauseVoice","stopVoice","uploadVoice","downloadVoice","chooseImage","previewImage","uploadImage","downloadImage","getNetworkType","openLocation","getLocation","hideOptionMenu","showOptionMenu","closeWindow","scanQRCode","chooseWXPay","openProductSpecificView","addCard","chooseCard","openCard"],f=t.wx=t.wx||{},g=f.SHARE_TYPE_APP="app",m=f.SHARE_TYPE_TIMELINE="timeline",v=f.SHARE_TYPE_WIEBO="weibo",w=f.SHARE_TYPE_QQ="qq",b={};b[g]="AppMessage",b[m]="Timeline",b[v]="Weibo",b[w]="QQ";var y=Bt.share,x={img:y.img||It+"icon.png",link:(u?y.link:"")||It,query:"",title:y.title||J.title||"火舞游戏",desc:y.desc||J.title||"火舞游戏"};t.getShare=function(e){return x[e]},t.setShare=function(e,r,i){if(_(e)){i=!!r;for(var s in e)t.setShare(s,e[s],i)}else if(e&&x.hasOwnProperty(e)&&S(e)&&S(r)&&r){if("link"===e){if(r=o(r,!1),!r)return t}else if("img"===e){if(r=o(r,!0),!r)return t}else"query"===e?x.link=D(x.link,r):u&&pt||"title"!==e&&"desc"!==e||r&&(J.title=r);var c=x[e];x[e]=r,n("share.set",e,c,r),!i&&d&&(a(g),a(m),a(v),a(w))}return t},f.sendFriend=function(e,n){return t.setShare(e,!0),i(g,n),this},f.sendTimeline=function(e,n){return t.setShare(e,!0),i(m,n),this},f.sendWeibo=function(e,n){return t.setShare(e,!0),a(v,n),this},pt&&t.env.wechat?h.slice(5).forEach(function(t){f[t]=function(n){e.wx&&e.wx[t](n)}}):f.hideOptionMenu=f.showOptionMenu=function(){};var k=[];if(pt&&!p){J.write('<script src="http://res.wx.qq.com/open/js/jweixin-1.0.0.js"></script>');var I="__cbhoowu"+Date.now();e[I]=function(t){e[I]=null,c(t)},J.write('<script src="http://api.wx.51h5.com/web/share/sign/id/ihoowu?cb='+I+'"></script>')}}(At);var sn,cn;At.setBanner=function(e){return v(sn,e),At},function(){var t=N("banner");t&&(sn=t,cn=N("banner","type"),sn>0&&At.ready(function(){if(e.BAIDU_DUP_require||x("http://dup.baidustatic.com/js/zm.js"),"1"===cn){var t=J.createElement("div");t.id="hw_banner_"+sn,M("body").appendChild(t),At.setBanner(t.id)}}))}(),At.showAd=function(){},At.hideAd=function(){},At.isAd=function(){return"no"!==Bt.appBanner},At.ready(o),At.ready(function(){for(var t,n="//hm.baidu.com/hm.js?0c906e9f94713174584881c774a94212",o=V+"hmt",r=J.getElementsByTagName("script"),i=r.length;i>t;t++)if(r[t].src.indexOf(n)>=0)return;e[o]=e[o]||[];var a=J.createElement("script");a.src=n,r[0].parentNode.insertBefore(a,r[0])}),At.ready(function(){for(var t,n=1253472040,o="//w.cnzz.com/q_stat.php?id="+n,r=V+"czc",i=J.getElementsByTagName("script"),a=i.length;a>t;t++)if(i[t].src.indexOf(o)>=0)return;e[r]=e[r]||[];var s=J.createElement("script");s.src=o,i[0].parentNode.insertBefore(s,i[0])})}(this),~function(e,t){var n=e.ih5game;if(n.channel===t){var o=n.home(!0)+"/op-",r=o+"zte.html";n.more=function(t){return t?r:void(e.location.href=r)},n.download=n.home=n.more}}(this,1014),~function(e,t){var n=e.ih5game;if(n.channel===t){var o="sinaweibo://snggame",r="http://weibo.com/u/5126161537",i=n.env.weibo?o:r;n.more=function(t){return t?i:void(e.location.href=i)},n.download=n.home=n.more}}(this,1016);