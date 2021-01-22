let express = require('express');
let app= express();

let fs = require('fs');//파일 호출관련 객체받기

let bodyParser = require("body-parser");
app.use(bodyParser.urlencoded({extended:false}));

app.use(express.static('public/'));

app.set('views','./views');//views폴더가 있어야한다. 
app.set('view engine','jade');//views폴더 안에 jade 확장자에 대해 설정하였다.

app.listen(3000,()=>{
    console.log('Connected 3000 port!');
})

app.get('/',(req,res)=>{
    
    res.sendfile('index.html');
})

app.post('/next',(req,res)=>{//로그인 페이지에서 버튼 눌렀을때
    
    

    if(req.body.login)
    {
        fs.readdir('data',(err,files)=>{
            if(err)//에러나면
            {
                res.status(500).send('Internal Server Error');
            }
            
            fs.exists(`data/${req.body.Id}`, (exists)=> { 
                if(exists)
                res.render('back',{loginResult:`${req.body.Id}님 환영합니다!`,back:"로그아웃하기"});
                else
                res.render('back',{loginResult:"로그인에 실패하였습니다.",back:'로그인창으로가기'});
            });
            
        })
    }
    else if(req.body.create)
    res.sendfile('create.html');
})
app.post('/',(req,res)=>{// 회원가입페이지에서 완료/취소버튼 눌렀을때

    let name = req.body.name;
    let Id = req.body.Id;
    let Password = req.body.Password;
    let description = `name = ${name}\nId = ${Id}\nPassword = ${Password}`;
    // /data폴더에 title을 이름으로 파일생성, description을 내용으로 저장
    fs.writeFile('data/'+Id,description,(err)=>{
        if(err){
            console.log(err);
            res.status(500).send('Internal Server Error');
        }
                
        res.redirect('/');
    });

})
