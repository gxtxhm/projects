let express = require("express"); //express를 요청하면 함수값이 반환된다. 
let app = express(); //이런식으로 사용한다.

let mysql      = require('mysql');
let db = mysql.createConnection({
  host     : 'localhost',
  user     : 'root',
  password : '111111',
  database : 'user' ,
  dateStrings : 'date'
});
db.connect();

let bodyParser = require("body-parser");
const { render } = require("jade");
app.use(bodyParser.urlencoded({extended:false}));

app.set('views','./views');//views폴더가 있어야한다. 
app.set('view engine','jade');//views폴더 안에 jade 확장자에 대해 설정하였다.



app.listen(3000, ()=> console.log('3000 port!'));

app.use(express.static('public/'));

//메인 화면 띄우기
app.get('/welcome/:id',(req,res)=>{
    let _list=``;
    let num=0;
    let output;
    
    db.query("SELECT * FROM article",(err,list)=>{
        if(err) throw err;
        list.forEach(element=>{
            num++;
            _list+=`<tr><td>${num}</td>`;
            _list+=`<td class="title"><a href="/article_list/${element.id}/${req.params.id}">${element.title}</a></td>`;
            _list+=`<td>${element.creater}</td>`;
            _list+=`<td>${element.date}</td>`;
            _list+=`<td>${element.viewer}</td>`;
            _list+="</tr>";
        })
    })
    
    setTimeout(()=>{
        output=`
        <!DOCTYPE html>
        <html lang="en">
        <head>
            <meta charset="UTF-8">
            <meta name="viewport" content="width=device-width, initial-scale=1.0">
            <title>Document</title>
            <link rel="stylesheet" href="/board.css">
        </head>
        <body>
            <div class="contents">
                <header>
                    <h1>게시판 만들기</h1>
                </header>
                <div class="user_ID">${req.params.id}</div>
                <article>
                    <div class="list_header">
                        <h2>목록</h2>
                        <form action="/create_article/${req.params.id}" method="get">
                            <input class="create_articleBtn" type="submit" value="글쓰기">
                        </form>
                    </div>
            
                    <table>
                        <tr>
                            <td>글번호</td>
                            <td class="title">제목</td>
                            <td>작성자</td>
                            <td>작성일</td>
                            <td>조회수</td>
                        </tr>
                        ${_list}
                    </table>
            
                </article>
            
            </div>
            
        </body>
        </html>
        `
    },200);
    
    setTimeout(() => {
        res.send(output);
    }, 200);
    
})
//글쓰기버튼 눌렀을때
app.get('/create_article/:id',(req,res)=>{
    res.render('create',{user_id:req.params.id});
})

//글쓰기 완료버튼 눌렀을때
app.post('/finishWrite',(req,res)=>{
    
    let aHead = req.body.article_head;
    let aBody = req.body.article_body;
    

    db.query(`INSERT INTO article (title,description,creater,date,comment,contents,viewer) VALUES("${aHead}","${aBody}","${req.body.user_id}",NOW(),0,"1",0)`,(err,list)=>{
        if(err)throw err;
        res.redirect(`/welcome/${req.body.user_id}`);
    })
    
})

//글 목록중 하나 눌렀을때
app.get('/article_list/:id/:user_id',(req,res)=>{
    db.query(`UPDATE article SET viewer=viewer+1 WHERE id=?;`,[req.params.id],(err,list)=>{if(err)throw err;})
    db.query(`SELECT * FROM article WHERE id=?`,[req.params.id],(err,list)=>{
        if(err)throw err;
        let array=[];
        array=list[0].contents.split('|');
        res.render('articleList',{Id:list[0].id,user_id:req.params.user_id,_title:list[0].title,_section:list[0].description,
            _length:list[0].comment,_contentsArray:array});
    })
    
})


//글 목록누른페이지에서 수정,삭제,댓글달기버튼 눌렀을때
app.post('/clickBtn',(req,res)=>{

    //delete버튼을 눌렀다면
    if(req.body.delete){//삭제버튼 눌렀을때

        db.query(`SELECT * FROM article WHERE id=?`,[req.body.id],(err,list)=>{
            //작성자랑 현재 로그인한 유저랑 같은 사람인가?
            if(req.body.user_id==list[0].creater)
            {
                db.query(`DELETE FROM article WHERE id=?`,[req.body.id],(err,list)=>{
                    if(err)throw err;
                    setTimeout(()=>{res.redirect(`/welcome/:${req.body.user_id}`);},100);
                })
            }
            setTimeout(()=>{res.redirect(`/welcome/${req.body.user_id}`);},100);
        })
        
    }
    else if(req.body.edit=="수정"){//수정버튼 눌렀을 때
        
        db.query(`SELECT * FROM article WHERE id=?`,[req.body.id],(err,list)=>{
            //작성자랑 현재 로그인한 유저랑 같은 사람인가?
            if(req.body.user_id==list[0].creater)
            {
                db.query(`UPDATE article SET title=?,description=? WHERE id=?`,[req.body.article_head,req.body.article_body,req.body.id],(err,list)=>{})    
                setTimeout(()=>{res.redirect(`/welcome/${req.body.user_id}`);},100);
            }
            setTimeout(()=>{res.redirect(`/welcome/${req.body.user_id}`);},100);
        })
        
        
    }
    else if(req.body.comment=="댓글 등록")//댓글버튼 눌렀을 때
    {
        let contents;
        db.query(`SELECT * FROM article WHERE id=?`,[req.body.id],(err,list)=>{
            contents=list[0].contents;
            console.log(contents);
        })
        setTimeout(()=>{
            contents=contents+'|'+req.body.user_id+' : '+req.body.addComment;
            db.query(`UPDATE article SET comment=comment+1,contents=? WHERE id=?`,[contents,req.body.id],(err,list)=>{})
        },300);
        
        
        setTimeout(()=>{res.redirect(`/welcome/${req.body.user_id}`);},400);
    }

})

/***************************************************************  로그인 기능들 ****************************************************************/
//로그인 메인화면
app.get('/',(req,res)=>{
    
    res.sendfile('index.html');
})

app.post('/next',(req,res)=>{//로그인 페이지에서 버튼 눌렀을때
    
    

    if(req.body.login)
    {
            db.query(`SELECT * FROM member WHERE id="${req.body.Id}" and password="${req.body.Password}"`,(error,results)=>{
                if (error){
                    res.status(500).send('Internal Server Error');
                }
                for(let i=0;i<results.length;i++)
                {
                    let name = results[i].name;
                    let id = results[i].id;
                    let pw = results[i].password;
                    console.log(results);
                    if(id==req.body.Id&&pw==req.body.Password)
                    {
                        res.render('back',{loginResult:`${name}님 환영합니다!`,route:`/welcome/${results[0].id}`,back:"시작하기"});
                    }
                }
                res.render('back',{loginResult:"로그인에 실패하였습니다.",route:'/',back:'로그인창으로가기'});
                
            })
    }
    else if(req.body.create)
    res.sendfile('create.html');
})
app.post('/',(req,res)=>{// 회원가입페이지에서 완료버튼 눌렀을때

    let name = req.body.name;
    let Id = req.body.Id;
    let Password = req.body.Password;

    
        db.query(`INSERT INTO member (name,id,password) VALUES("${name}","${Id}","${Password}")`, (error, results) => {
            if (error){
                console.log(error);
            }
            console.log("Complete Insert!");
            res.redirect('/');
        });
    
})
