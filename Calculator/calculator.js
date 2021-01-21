'user strict'

let numberBtn = document.querySelectorAll('.number');//숫자 버튼 10개
let textBtn = document.querySelectorAll('.text');//그외 문자버튼들 14개

let InputNum = document.querySelector('.InputNum p');//버튼 누를때 마다 갱신되는 p태그
let InputCalculator = document.querySelector('.InputCalculator p');// = 눌렀을때 표시되는 p태그

let ResultList = document.querySelector('#ResultList');//계산기록을 표현하는 ul태그

let isInput = false;        //숫자입력이 된 상태인가?
let NumofParentheses = 0;  // '(' 가 입력되었는가?


//let a = numberBtn[1].id;//string값 반환

//계산기록 목록추가하는함수
function createResultList(){
    let li= document.createElement('li');
    let formula = document.createElement('p');
    formula.classList.add('formula');
    formula.innerText = InputCalculator.innerHTML;
    let result_formula = document.createElement('p');
    result_formula.classList.add('result_formula');
    result_formula.innerText = InputNum.innerHTML;

    li.appendChild(formula);
    li.appendChild(result_formula);

    ResultList.appendChild(li);

    li.addEventListener('click',()=>{
        InputCalculator.innerHTML = formula.innerHTML;
        InputNum.innerHTML = result_formula.innerHTML;
        
    })
}




//pTag 2개내용 초기화해주는 함수
function InitPTagAll(){
    InputNum.innerHTML =0;
    InputCalculator.innerHTML =0;
}
InitPTagAll();//처음에 0이 떠있게하는것
//숫자버튼 클릭체크 
numberBtn.forEach(element => {
    element.addEventListener('click',()=>{
        //InputNum = document.querySelector('.InputNum p');
        if(element.id==0&&IsOverzero()==0)
        {
            
        }
        else
        {
            if(IsFirstInsert(InputNum)===1||isInput===false)
            InputNum.innerHTML = element.id;
            else
            InputNum.innerHTML += element.id;

            isInput=true;
        }

    })
});
//문자버튼 체크
textBtn.forEach(element =>{

    element.addEventListener('click',()=>{

        switch(element.id){
            case "removeAll":                        // 'C' 버튼
                InitPTagAll();break;
            case "ParenthesesOpen":                  // '(' 버튼
            {
                if(IsFirstInsert(InputCalculator)===1)    
                InputCalculator.innerHTML='(';
                else
                InputCalculator.innerHTML+='(';
                
                isInput=false;
                NumofParentheses++;
                break; 
            }
            case "ParenthesesClose":                 // ')' 버튼
                if(IsFirstInsert(InputNum)!==1&&NumofParentheses>0)    
                {
                    if(isInput===false)
                    InputCalculator.innerHTML+=')';
                    else
                    {
                        InputCalculator.innerHTML+=InputNum.innerHTML;
                        InputCalculator.innerHTML+=')';
                    }
                    isInput=false;
                    NumofParentheses--;
                }
                break;
            case "backSpace":                        // 한칸 빼는 백스페이스모양버튼 
                InputNum.innerHTML = InputNum.innerHTML.substr(0,InputNum.innerHTML.length-1);
                if(InputNum.innerHTML.length===0)InputNum.innerHTML =0;
                break;
            case "division":                        // 나누기 버튼
                if(IsFirstInsert(InputNum)===0)
                forRules_cal('/');
                break;
            case "multifly":                        // 곱하기 버튼
                if(IsFirstInsert(InputNum)===0)
                forRules_cal('*');
                break;
            case "subtract":                        // 빼기 버튼
                if(IsFirstInsert(InputNum)===0)
                forRules_cal('-');
                break;
            case "add":                             // 더하기 버튼
                if(IsFirstInsert(InputNum)===0)
                forRules_cal('+');
                break;
            case "changeSign":                      // +/- 버튼
                if(IsFirstInsert(InputNum)===0)
                {
                    InputNum.innerHTML=String(Number(InputNum.innerHTML)*(-1));
                }
                break;
            case "substitution":                    // = 버튼
                if(isInput===true)
                InputCalculator.innerHTML += InputNum.innerHTML;
                //계산
                let imsiString = ConvToRPNExp(InputCalculator.innerHTML);
                 // InputNum 에 결과 띄우기 
                InputNum.innerHTML = String(EvalRPNExp(imsiString));
                InputCalculator.innerHTML += '=';
                isInput=false;
                createResultList();
                break;
                // InputNum 과 InputCalculator innerHTML 오른쪽 목록에 올리기
        }
    })
    
})
//위의 p태그로 수식 옮기기
function forRules_cal(calType){
    
    

    if(isInput===false&&IsFirstInsert(InputCalculator)===0)
    {
        InputCalculator.innerHTML+=calType;return;
    }

    if(IsFirstInsert(InputCalculator)===1||isInput==false)
    InputCalculator.innerHTML=(InputNum.innerHTML+calType);
    else
    InputCalculator.innerHTML+=(InputNum.innerHTML+calType);

    isInput=false;
}



//처음 입력인가 체크
function IsFirstInsert(inputType){
    if(inputType.innerHTML=="0")
    return 1;
    else 
    return 0;
}
//처음에 0입력할때 0계속 늘어나는 것 방지
function IsOverzero(){
    
    if(Number(InputNum.innerHTML)>0)
    return 1;
    else 
    return 0;
}