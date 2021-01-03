'user strict'


let pagescrollcnt=0;
let startData = 5;
/*---------------------------------- 스크롤 기능 시작-------------------------------------------  */
//무작위 문장 생성
function randomString(length) {
let chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXTZabcdefghiklmnopqrstuvwxyz";
let string_length = length;
let randomstring = '';
for (let i=0; i<string_length; i++) {
let rnum = Math.floor(Math.random() * chars.length);
randomstring += chars.substring(rnum,rnum+1);
}

return randomstring;
}

//15개의 리스트 생성
function createElement(){

  let forlength=15;
  const pagescrollcnt=0;
   if(pagescrollcnt==6)
   forlength=5;

   for(let i=0;i<forlength;i++)
   {
    let div = document.createElement('div');
    div.className = "post";
    div.id = i+1+startData + pagescrollcnt*15;

    let listnumber = document.createElement('div');
    listnumber.className ="listnumber";
    let p = document.createElement('p');
    p.innerText = i+1+startData +pagescrollcnt*15;
    listnumber.appendChild(p);


    let listcontent = document.createElement('div');
    listcontent.className = "listcontent";
    let p1= document.createElement('p');
    p1.innerHTML = randomString(20);
    p1.className="content_head"
    let p2 = document.createElement('p');
    p2.innerText = randomString(100);
    p2.className = "content_body";
    
    listcontent.appendChild(p1);
    listcontent.appendChild(p2);

    div.appendChild(listnumber);
    div.appendChild(listcontent);

    let section = document.getElementsByClassName('Section');
    section[0].appendChild(div);

    
   }
   pagescrollcnt++;
   
}

//스크롤을 사용했는지 확인
window.addEventListener('scroll', () => {
	let scrollLocation = document.documentElement.scrollTop; // 현재 스크롤바 위치
	let windowHeight = window.innerHeight; // 스크린 창
	let fullHeight = document.body.scrollHeight; //  margin 값은 포함 x

	if((scrollLocation + windowHeight >= fullHeight)&&(pagescrollcnt<=6)){//스크롤바가 맨 밑으로 내려갔으면 진행
      createElement();
	}
})

/*---------------------------------- 스크롤 기능 끝-------------------------------------------  */

// -------------------------------------검색 기능 시작-------------------------------------------------





function OnkeyUp()//키가 눌리면 모든 .post 목록을 살피고 문자열이 존재하는 것만 창에 띄운다.
{
   let postArr = document.querySelectorAll('.post');
   let input = document.querySelector('input');


      if(input.value.length===0)
      {
         postArr.forEach((element)=>{
            element.classList.remove('displayNone');
         });
         return 0;
      }

      postArr.forEach(post =>{

         let p_head = post.querySelector('.content_head').innerText;
         let p_body = post.querySelector('.content_body').innerText;

         if(p_head.indexOf(input.value)> -1 || p_body.indexOf(input.value)>-1)// 검색한 문자가 있다면
         {
            post.classList.remove('displayNone');
         }
         else
         {
            post.classList.add('displayNone');
         }
         
      })

}
// 눌렀는지 확인
window.addEventListener('input',OnkeyUp);
// -------------------------------------검색 기능 끝-------------------------------------------------