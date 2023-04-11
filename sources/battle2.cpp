// Card &card1 = this->p1_.getCard();
//     Card &card2 = this->p2_.getCard();
//     int match = battle(this->p1_,this->p2_,card1,card2);
//     if(match==1){
//         this->p1_.cardsWon();
//         this->last_turn= this->getTurn(this->p1_.getName(),card1)+
//                         this->getTurn(this->p2_.getName(),card2)+
//                         this->p1_.getName() + " won.\n";
//         this->p1_.addWin();
//         this->p2_.addLoss();                
//         this->summary+=this->last_turn;  
//     }
//     else if(match==2){
//         this->p2_.cardsWon();
//         this->last_turn= this->getTurn(this->p1_.getName(),card1)+
//                         this->getTurn(this->p2_.getName(),card2)+
//                         this->p2_.getName() + " won.\n";
//         this->p2_.addWin();
//         this->p1_.addLoss();                  
//         this->summary+=this->last_turn;   
//     }
//     else if(match==0){
//         bool winner= false;
//         while(winner==false){
//             this->last_turn=" Draw. ";
//             this->summary+=this->last_turn; 
//             this->p1_.addDraw();
//             this->p2_.addDraw();
//             if(this->p1_.stacksize()>=2){
//                 this->p1_.getCard();
//                 this->p2_.getCard();
//                 Card &card11 = this->p1_.getCard();
//                 Card &card21 = this->p2_.getCard();
          
//                 match=battle(this->p1_,this->p2_,card11,card21);
//                 if(match==1){
//                     this->p1_.cardsWon();
//                     this->last_turn= this->getTurn(this->p1_.getName(),card11)+
//                                     this->getTurn(this->p2_.getName(),card21)+
//                                     this->p1_.getName() + " won.\n";
//                     this->p1_.addWin();
//                     this->p2_.addLoss();                
//                     this->summary+=this->last_turn; 
//                     winner=true; 
//                 }
//                 else if(match==2){
//                     this->p2_.cardsWon();
//                     this->last_turn= this->getTurn(this->p1_.getName(),card11)+
//                                     this->getTurn(this->p2_.getName(),card21)+
//                                     this->p2_.getName() + " won.\n";
//                     this->p2_.addWin();
//                     this->p1_.addLoss();                  
//                     this->summary+=this->last_turn;   
//                     winner=true;
//                 }
                
//             }
//             else{
//                 this->p1_.addDraw();
//                 this->p2_.addDraw();
//                 while(this->p1_.stacksize()>0){
//                     this->p1_.getCard();
//                     this->p2_.getCard();
//                     this->p1_.cardsWon();
//                     this->p2_.cardsWon();   
//                 }

//             }
//         }
//     }