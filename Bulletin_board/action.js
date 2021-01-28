let express = require("express"); //express를 요청하면 함수값이 반환된다. 
let app = express(); //이런식으로 사용한다.
let fs = require('fs'); 

let bodyParser = require("body-parser");
const { render } = require("jade");
app.use(bodyParser.urlencoded({extended:false}));

app.set('views','./views');//views폴더가 있어야한다. 
app.set('view engine','jade');//views폴더 안에 jade 확장자에 대해 설정하였다.



app.listen(3000, ()=> console.log('3000 port!'));

app.use(express.static('public/'));

//메인 화면 띄우기
app.get('/',(req,res)=>{
    let _list=``;
    let num=0;
    let output;
    fs.readdir('data',(err,files)=>{
        
        //console.log("files:"+files);
        files.forEach(element => {
            
            fs.readFile(`data/${element}`, function(err, data) {
                num++;
                if(err) throw err;
                _list+=`<tr><td>${num}</td>`;
                
                let array = data.toString().split(",");
                for(i in array) {
                    let _array = array[i].toString().split(":");
                    //console.log(_array[0]);
                    if(_array[0]==="title")
                    {
                        _list=_list+`<td class="title"><a href="/article_list/${_array[1]}">${_array[1]}</a></td>`;
                    }
                    else if(_array[0]==="description"||_array[0]=="contents"||_array[0]=="comment")
                    {

                    }
                    else
                    {
                        _list=_list+`<td>${_array[1]}</td>`;
                    }
                    
                }
                _list=_list+`</tr>`;
                
            });
        });
        
    })
    
    //setTimeout(()=>console.log("listFinish:"+ _list),1000);
    
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
            
                <article>
                    <div class="list_header">
                        <h2>목록</h2>
                        <form action="/create_article" method="get">
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
    },1000);
    
    setTimeout(() => {
        res.send(output);
    }, 1000);
    
})
//글쓰기버튼 눌렀을때
app.get('/create_article',(req,res)=>{
    res.render('create');
})

//글쓰기 완료버튼 눌렀을때
app.post('/finishWrite',(req,res)=>{
    
    let aHead = req.body.article_head;
    let aBody = req.body.article_body;
    
    
    let description = `title:${aHead},description:${aBody},creater:박성진,date:${Date()},comment:0,contents:,viewer:0`;
    // /data폴더에 title을 이름으로 파일생성, description을 내용으로 저장
    fs.writeFile('data/'+aHead,description,(err)=>{
        if(err){
            console.log(err);
            res.status(500).send('Internal Server Error');
        }
                
        res.redirect('/');
    });
    
})

//글 목록중 하나 눌렀을때
app.get('/article_list/:title',(req,res)=>{
    let newDescription=``;
    fs.readdir('data',(err,files)=>{

        files.forEach(element =>{
            //클릭한 파일이면
            if(element===req.params.title)
            {
                let t;
                let s;
                let commentLength;
                let contentsArray;
                fs.readFile(`data/${element}`, function(err, data) {
                    
                    if(err) throw err;
                    
                    
                    
                    let array = data.toString().split(",");
                    console.log("array : "+array);
                    for(i in array) {
                        let _array = array[i].toString().split(":");
                        
                        if(_array[0]==="title")
                        {
                            t=_array[1];
                            newDescription+=`${_array[0]}:${_array[1]},`;
                            
                        }
                        else if(_array[0]==="description")
                        {
                            s=_array[1];
                            newDescription+=`${_array[0]}:${_array[1]},`;
                        }
                        else if(_array[0]==="viewer")
                        {
                            newDescription+=`${_array[0]}:${Number(_array[1])+1}`;
                        }
                        else if(_array[0]==="comment")
                        {
                            commentLength=Number(_array[1]);
                            console.log("commentLength : "+Number(_array[1]));
                            newDescription+=`${_array[0]}:${_array[1]},`;
                        }
                        else if(_array[0]==="contents")
                        {
                            newDescription+=`${_array[0]}:${_array[1]},`;
                            contentsArray=_array[1].toString().split("|");
                            console.log("contentsArray : "+contentsArray);
                            
                        }
                        else
                        {
                            newDescription+=`${_array[0]}:${_array[1]},`;
                        }
                        
                        
                    }
                    
                    
                });
                
                
                    
                setTimeout(()=>{
                    fs.writeFile(`data/${element}`,newDescription,"utf-8",(err)=>{
                        console.log(element + '파일 수정하러 들어왔어요!!');
                        if(err){
                            //console.log(err);
                            res.status(500).send('Internal Server Error');
                        }
                    })
                },900);
                
                    setTimeout(()=>{
                        res.render('articleList',{_title:t,_section:s,_length:commentLength,_contentsArray:contentsArray});
                        
                    },1000);
                
            }
        })
    })

    
})


//글 목록누른페이지에서 수정,삭제,댓글달기버튼 눌렀을때
app.post('/clickBtn',(req,res)=>{
    console.log("i'm here!");
    //delete버튼을 눌렀다면
    if(req.body.delete){//삭제버튼 눌렀을때
        
        fs.readdir('data',(err,files)=>{
            files.forEach(element =>{
                if(element===req.body.article_head)
                {
                    fs.unlink(`data/${element}`,()=>{});
                    res.redirect('/');
                }
            })
        })
    }
    else if(req.body.edit=="수정"||req.body.comment=="댓글 등록"){//수정버튼이나 댓글등록버튼 눌렀을 때
        
        console.log(req.body.edit + " : "+req.body.comment);
        let newDescription=``;
    fs.readdir('data',(err,files)=>{

        files.forEach(element =>{
            //클릭한 파일이면
            if(element===req.body.article_head)
            {
                let t;
                let s;
                
                fs.readFile(`data/${element}`, function(err, data) {
                    
                    if(err) throw err;
                    
                    
                    
                    let array = data.toString().split(",");
                    //console.log("array : "+array);
                    for(i in array) {
                        let _array = array[i].toString().split(":");
                        
                        if(_array[0]==="title")
                        {
                            t=_array[1];
                            newDescription+=`${_array[0]}:${req.body.article_head},`;
                            //console.log("article_head : "+req.body.article_head);
                        }
                        else if(_array[0]==="description")
                        {
                            s=_array[1];
                            newDescription+=`${_array[0]}:${req.body.article_body},`;
                            //console.log("article_body : "+req.body.article_body);
                        }
                        else if(_array[0]==="viewer")
                        {
                            newDescription+=`${_array[0]}:${_array[1]}`;
                        }
                        else if(_array[0]==="comment")
                        {
                            console.log("hi comment");
                            if(req.body.comment==="댓글 등록")
                            {
                                newDescription+=`${_array[0]}:${Number(_array[1])+1},`;
                                console.log(`comment : ${Number(_array[1])+1}`)
                            }
                            else
                                newDescription+=`${_array[0]}:${Number(_array[1])},`;
                        }
                        else if(_array[0]==="contents")
                        {
                            if(req.body.comment==="댓글 등록"){
                                let contentsArr = _array[1].toString().split("|");
                                newDescription+=`${_array[0]}:`
                                contentsArr.forEach(element=>{
                                    if(element==""){}
                                    else
                                        newDescription+=`${element}|`;
                                })
                                newDescription+=`${req.body.addComment},`;
                                console.log("addcomment : "+req.body.addComment);
                            }
                            else
                            {
                                newDescription+=`${_array[0]}:${_array[1]},`
                            }
                        }
                        else
                        {
                            newDescription+=`${_array[0]}:${_array[1]},`;
                        }
                        
                        
                    }
                    
                    
                });
                
                
                    
                setTimeout(()=>{
                    fs.writeFile(`data/${element}`,newDescription,"utf-8",(err)=>{
                        console.log(element + '파일 수정하러 들어왔어요!!');
                        if(err){
                            //console.log(err);
                            res.status(500).send('Internal Server Error');
                        }
                    })
                },900);
                
                    
                
            }
        })
    })
        
            setTimeout(()=>{res.redirect('/');},1000);
        
    }

})