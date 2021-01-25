'user strict'



const stack = new Stack(); //스택 생성

//중위표기법을 후위표기법으로 바꾸는 함수
function ConvToRPNExp(exp){//중위표기법이 적힌 문자열을 매개변수로 받는다.

    let Postfix=""; //후위표기법이 담긴 변수
    
    for(let i=0;i<exp.length;i++){
        //음수면
        if(exp[i]==='-'&&isNaN(exp[i-1])){
            let imsi=exp[i];

            while(true){
                let j;
                for(j=i+1;j<exp.length;j++){
                    if(!isNaN(exp[j])){
                        imsi+=exp[j];
                    }
                    else break;
                }
                //i포문 대신 j포문으로 이동한 만큼 i를 증가시킨다.
                //식이 헷갈린다..;;
                i+=j-(i+1);
                
                break;
            }
            Postfix+=imsi+',';
        }


        else if(!isNaN(exp[i])){ //isNaN == is Not a Number   숫자가 아니면 true반환
            //숫자면 바로 새 문자열에 저장
            let imsi=exp[i];
            
            // i를 기준으로 연산자가 나올때까지 j값으로 대체하여 그 뒤를 살핀다. 
            // 값들을 문자열로 하나의 숫자를 만들고 그를 새 문자열에 저장하고 , 를 붙여서 숫자를 구분한다.
            // 숫자를 만들었으니 이동한만큼 i를 증가시킨다. 
            while(true){
                let j;
                for(j=i+1;j<exp.length;j++){
                    if(!isNaN(exp[j])){
                        imsi+=exp[j];
                    }
                    else break;
                }
                //i포문 대신 j포문으로 이동한 만큼 i를 증가시킨다.
                //식이 헷갈린다..;;
                i+=j-(i+1);
                
                break;
            }
            Postfix+=imsi+',';
            
            
        }
        else{
            
                switch(exp[i]){
                    case '(':
                        stack.push(exp[i]);
                        break;
                    case ')':
                        while(stack.peek()!=='('){
                            Postfix+=stack.pop();
                        }
                        stack.pop();
                        break;
                    case '+':case '-':case '*':case '/':
                        while(!stack.isEmpty()&&WhoPrecOp(stack.peek(),exp[i])>=0){
                            Postfix+=stack.pop();
                            Postfix+=',';
                        }
                        stack.push(exp[i]);
                        break;
                    default:
                        break;
                }
            }
        }
        //마지막 남은 연산자들 뒤에 다 붙이기
        while(!stack.isEmpty()){
            {
                Postfix+=stack.pop();
                Postfix+=',';
            }
    }
        console.log(Postfix);
        return Postfix;
}



function GetOpPrec( op)//op의 우선순위 정보 반환
{
	switch (op)
	{
	case '*':
	case '/': 
		return 5;
	case '+':
	case '-':
		return 3;
	case '(':
		return 1;
	default:
		return -1;
	}
}

function WhoPrecOp( op1,  op2)//op1,op2 를 비교하여 우선순위 높은지 판단
{
	let Preop1 = GetOpPrec(op1);
	let Preop2 = GetOpPrec(op2);

	if (Preop1 > Preop2)
	{
		return 1;
	}
	else if (Preop1 < Preop2)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}