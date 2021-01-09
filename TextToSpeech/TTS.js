let createAreaButton = document.querySelector('.toggleBtn');
let TTSArea = document.querySelector('.TTSArea');
let closeBtn = document.querySelector('.CloseBtn');
let toggleBox = document.querySelectorAll(".TTSBox");
let ReadBtn = document.querySelector('.RBtn');
let Textarea = document.querySelector('#text');
let voicesSelect = document.querySelector('#Choice-lang');

//EventListener 

//ToggleTextBox버튼 클릭시 
createAreaButton.addEventListener('click',()=>{
    TTSArea.classList.add('show');
});
//TextBox에서 x버튼 눌렀을 시
closeBtn.addEventListener('click',()=>TTSArea.classList.remove('show'));
//12개의 박스 클릭 이벤트
toggleBox.forEach(element => {
    element.addEventListener('click',()=>{

        let key = element.querySelector('p');
        setTextMessage(key.innerText);
        speakText();
    });
});

////////////////////////////////////


//Text - To - Speech

// Init speech synth
const message = new SpeechSynthesisUtterance();

// Store voices
let voices = [];

function getVoices() {
  voices = speechSynthesis.getVoices();

  voices.forEach(voice => {
    const option = document.createElement('option');

    option.value = voice.name;
    option.innerText = `${voice.name} ${voice.lang}`;

    voicesSelect.appendChild(option);
  });
}

// Set text
function setTextMessage(text) {
  message.text = text;
}

// Speak text
function speakText() {
  speechSynthesis.speak(message);
}

// Set voice
function setVoice(e) {
  message.voice = voices.find(voice => voice.name === e.target.value);
}

// Voices changed
speechSynthesis.addEventListener('voiceschanged', getVoices);


// Change voice
voicesSelect.addEventListener('change', setVoice);

// Read text button
ReadBtn.addEventListener('click', () => {
  setTextMessage(Textarea.value);
  speakText();
});