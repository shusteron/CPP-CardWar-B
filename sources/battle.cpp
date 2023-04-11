// bool winner = false;
//     while(winner==false && this->p1_.stacksize()>0){
//         Card card1 = this->p1_.getCard();
//         Card card2 = this->p2_.getCard();
//         if(card1.getValue() == 1){
//             if(card2.getValue()==2){
//                 this->p2_.cardsWon();
//                 this->last_turn= this->getTurn(this->p1_.getName(),card1)+
//                         this->getTurn(this->p2_.getName(),card2)+
//                         this->p2_.getName() + " won.\n";
//                 this->p2_.addWin();
//                 this->p1_.addLoss();                  
//                 this->summary+=this->last_turn;  
//                 winner=true;
//             }
//             else{
//                 this->p1_.cardsWon();
//                 this->last_turn= this->getTurn(this->p1_.getName(),card1)+
//                                 this->getTurn(this->p2_.getName(),card2)+
//                                 this->p1_.getName() + " won.\n";
//                 this->p1_.addWin();
//                 this->p2_.addLoss();                
//                 this->summary+=this->last_turn;       
//                 winner=true;
//             }
//         }
//         else if(card2.getValue() == 1){
//             if(card1.getValue()==2){
//                 this->p1_.cardsWon();
//                 this->last_turn= this->getTurn(this->p1_.getName(),card1)+
//                                 this->getTurn(this->p2_.getName(),card2)+
//                                 this->p1_.getName() + " won.\n";
//                 this->p1_.addWin();
//                 this->p2_.addLoss();                
//                 this->summary+=this->last_turn;       
//                 winner=true;

//             }
//             else{
//                  this->p2_.cardsWon();
//                 this->last_turn= this->getTurn(this->p1_.getName(),card1)+
//                         this->getTurn(this->p2_.getName(),card2)+
//                         this->p2_.getName() + " won.\n";
//                 this->p2_.addWin();
//                 this->p1_.addLoss();                  
//                 this->summary+=this->last_turn;  
//                 winner=true;

//             }
//         }
//         else if(card1.getValue()< card2.getValue()){
//             this->p2_.cardsWon();
//             this->last_turn= this->getTurn(this->p1_.getName(),this->p1_.getCard())+
//                             this->getTurn(this->p2_.getName(),this->p2_.getCard())+
//                             this->p2_.getName() + " won.\n";
//             this->p2_.addWin();
//             this->p1_.addLoss();                  
//             this->summary+=this->last_turn;    
//             winner=true;
//         }
//         else if(card1.getValue() > card2.getValue()){
//             this->p1_.cardsWon();
//             this->last_turn= this->getTurn(this->p1_.getName(),this->p1_.getCard())+
//                             this->getTurn(this->p2_.getName(),this->p2_.getCard())+
//                             this->p1_.getName() + " won.\n";
//             this->p1_.addWin();
//             this->p2_.addLoss();                
//             this->summary+=this->last_turn;  
//         }
//         else if(card1.getValue() == card2.getValue()){
//             if(this->p1_.stacksize()>=2){
//                 for(int i=0;i<2;i++){
//                     card1 = this->p1_.getCard();
//                     card2 = this->p2_.getCard();
//                 }

//             }
//         }
            
        
//     }