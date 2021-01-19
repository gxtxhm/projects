'use strict'

let DataBase = [{
    name : 'Chinon Apple Tarts',
    eat : ['Dessert','French'],
    material : ['Puff Pastry - 320g',
                'Dark Brown Soft Sugar - 4 tbs',
                'Braeburn Apples - 3',
                'Red Wine Jelly - 4 tbs',
                'Creme Fraiche - 100ml',
                'Icing Sugar - 1 tbs',
                'Cardamom - 3'],
    img : '/image/apple1.jpg',
    description : 'To make the red wine jelly, put the red wine, jam sugar, star anise, clove, cinnamon stick, allspice, split vanilla pod and seeds in a medium saucepan. Stir together, then heat gently to dissolve the sugar. Turn up the heat and boil for 20 mins until reduced and syrupy. Strain into a small, sterilised jam jar and leave to cool completely. Will keep in the fridge for up to 1 month. Take the pastry out of the fridge and leave at room temperature for 10 mins, then unroll. Heat the grill to high and heat the oven to 180C/160C fan/gas 4. Cut out 2 x 13cm circles of pastry, using a plate as a guide, and place on a non-stick baking sheet. Sprinkle each circle with 1 tbsp sugar and grill for 5 mins to caramelise, watching carefully so that the sugar doesn’t burn. Remove from the grill. Can be done a few hours ahead, and left, covered, out of the fridge. Peel, quarter and core the apples, cut into 2mm-thin slices and arrange on top of the pastry. Sprinkle over the remaining sugar and pop in the oven for 20-25 mins until the pastry is cooked through and golden, and the apples are softened. Remove and allow to cool slightly. Warm 3 tbsp of the red wine jelly in a small pan over a low heat with 1 tsp water to make it a little more runny, then brush over the top of the tarts. Tip the crème fraîche into a bowl, sift over the icing sugar and cardamom, and mix together. Carefully lift the warm tarts onto serving plates and serve with the cardamom crème fraîche.'

},{
    name : 'Apple Frangipan Tart',
    eat : ['Dessert','British'],
    material : ['digestive biscuits - 175g/6oz',
                'butter - 75g/3oz',
                'Bramley apples - 200g/7oz',
                'butter, softened - 75g/3oz',
                'caster sugar - 75g/3oz'],
    img : '/image/apple2.jpg',
    description : 'Preheat the oven to 200C/180C Fan/Gas 6. Put the biscuits in a large re-sealable freezer bag and bash with a rolling pin into fine crumbs. Melt the butter in a small pan, then add the biscuit crumbs and stir until coated with butter. Tip into the tart tin and, using the back of a spoon, press over the base and sides of the tin to give an even layer. Chill in the fridge while you make the filling. Cream together the butter and sugar until light and fluffy. You can do this in a food processor if you have one. Process for 2-3 minutes. Mix in the eggs, then add the ground almonds and almond extract and blend until well combined. Peel the apples, and cut thin slices of apple. Do this at the last minute to prevent the apple going brown. Arrange the slices over the biscuit base. Spread the frangipane filling evenly on top. Level the surface and sprinkle with the flaked almonds. Bake for 20-25 minutes until golden-brown and set. Remove from the oven and leave to cool for 15 minutes. Remove the sides of the tin. An easy way to do this is to stand the tin on a can of beans and push down gently on the edges of the tin. Transfer the tart, with the tin base attached, to a serving plate. Serve warm with cream, crème fraiche or ice cream.'
},{
    name : 'Lamb and Lemon Souvlaki',
    eat : ['Lamb','Greek'],
    material : ['Garlic - 2 cloves', 
                'Sea Salt - 2 tsp',
                'Olive Oil - 4 tbs',
                'Lemon - Zest and juice of 1',
                'Dill - 1 tbs',
                'Lamb Leg - 750g'],
    img : '/image/apple3.jpg',
    description : 'Pound the garlic with sea salt in a pestle and mortar (or use a small food processor), until the garlic forms a paste. Whisk together the oil, lemon juice, zest, dill and garlic. Mix in the lamb and combine well. Cover and marinate for at least 2 hrs or overnight in the fridge. If you’re going to use bamboo skewers, soak them in cold water. If you’ve prepared the lamb the previous day, take it out of the fridge 30 mins before cooking. Thread the meat onto the soaked or metal skewers. Heat the grill to high or have a hot griddle pan or barbecue ready. Cook the skewers for 2-3 mins on each side, basting with the remaining marinade. Heat the pitta or flatbreads briefly, then stuff with the souvlaki. Add Greek salad (see "Goes well with", right) and Tzatziki (below), if you like.'
}];

let resultSearch = document.querySelector('.result_search');
let InputBox = document.querySelector('#searchInput');
let SearchBtn = document.querySelector('#searchBtn');
let list = document.querySelectorAll('.result_list');


function ClickItem(){
    
}

SearchBtn.onclick = ()=>{
    
    let i;
    let findIdx=[];
    let IsInsert=false;
    for(i=0;i<DataBase.length;i++){
        
        console.log(InputBox.value);
        if(DataBase[i].name.indexOf(InputBox.value)!==-1)
        {
            console.log(DataBase[i].name+' : '+InputBox.value);
            findIdx[i]=i;//몇번 오브젝트인지 인덱스 값을 findIdx배열에 저장
            IsInsert=true;
        }
        else
            findIdx[i]=-1;
    }
    createList(findIdx,IsInsert);
    list = document.querySelectorAll('.result_list');
    list.forEach(element => {
        element.addEventListener('click',ClickItem);
    });
}

function removeulTag(){
    let ul = document.querySelector('.result_search ul');
    ul.parentNode.removeChild(ul);
    let h2= document.querySelector('.result_search h2');
    h2.parentNode.removeChild(h2);
}

function createList(findIdx,IsInsert){
    
    let ul = document.createElement('ul');
    let h2 = document.createElement('h2');
    

    if(IsInsert===false)
    {
        let H2 = document.querySelector('h2');
        H2.innerText = "There are no search results. Try again!";
        return;
    }
    h2.innerText = "Search results for '"+InputBox.value+"'";
    resultSearch.appendChild(h2);
    removeulTag();

    

    for(let i=0;i<findIdx.length;i++)
        {
            
            if(findIdx[i]!==-1)
            {
                let li = document.createElement('li');
                let div = document.createElement('div');
                div.classList.add('result_list');
                div.id=DataBase[i].name;
                let img = document.createElement('img');
                img.src = DataBase[i].img;
                div.appendChild(img);
                li.appendChild(div);
                ul.appendChild(li);
            }
        }
    resultSearch.appendChild(ul);
}
