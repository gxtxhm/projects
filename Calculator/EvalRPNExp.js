'user strict'



const stack1 = new Stack(); //스택 생성

function EvalRPNExp(exp){
    
    for(let i=0;i<exp.length;i++){
        console.log(i);
        //음의정수면
        if(exp[i]==='-'&&!isNaN(exp[i+1])){
            let j;
            let imsi=exp[i];
            for(j=i+1;exp[j]!==',';j++){
                
                    imsi+=exp[j];
                
                    
            }
            i+=j-i;
            console.log(imsi);
            stack.push(Number(imsi));
        }

        //양의정수면
        else if(!isNaN(exp[i])){

            let j;
            let imsi=exp[i];
            for(j=i+1;exp[j]!==',';j++){
                
                    imsi+=exp[j];
                
                    
            }
            i+=j-i;
            console.log(imsi);
            stack.push(Number(imsi));
        }

        //연산자면
        else{
            if(exp[i]==',')
            {
                continue;
            }
            
            let num2 = stack.pop();
            let num1 = stack.pop();

            switch(exp[i]){
                case '*':
                    stack.push(num1*num2);break;
                case '/':
                    stack.push(num1/num2);break;
                case '+':
                    stack.push(num1+num2);break;
                case '-':
                stack.push(num1-num2);break;
            }
        }
    }
    return stack.pop();
}