'user strict'

class Stack {
    constructor() {
        this._arr = [];
    }
    push(item) {
        this._arr.push(item);
    }
    pop() {
        return this._arr.pop();
    }
    peek() {
        return this._arr[this._arr.length - 1];
    }
    isEmpty(){
        if(this._arr.length===0)return 1;
        else return 0;
    }
}