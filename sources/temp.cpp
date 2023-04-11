// if(this->p1_.peek() > this->p2_.peek()){
//         this->p1_.cardsWon();
//         this->last_turn= this->getTurn(this->p1_.getName(),this->p1_.getCard())+
//                         this->getTurn(this->p2_.getName(),this->p2_.getCard())+
//                         this->p1_.getName() + " won.\n";
//         this->p1_.addWin();
//         this->p2_.addLoss();                
//         this->summary+=this->last_turn;                

//     }
//     else if (this->p1_.peek() < this->p2_.peek())
//     {
//         this->p2_.cardsWon();
//         this->last_turn= this->getTurn(this->p1_.getName(),this->p1_.getCard())+
//                         this->getTurn(this->p2_.getName(),this->p2_.getCard())+
//                         this->p2_.getName() + " won.\n";
//         this->p2_.addWin();
//         this->p1_.addLoss();                  
//         this->summary+=this->last_turn;                
                       
//     }
//     // In case of draw.
//     else{    
//         this->p1_.addDraw();
//         this->p2_.addDraw();             
//         bool draw_winner=false;
//         vector<Card> alice; // Stands for p1_ stack.
//         vector<Card> bob;   // Stands for p2_ stack.
//         while(draw_winner==false && this->p1_.stacksize()>0){
//             this->last_turn=" Draw. ";
//             this->summary+=this->last_turn; 
//             this->p1_.addDraw();
//             this->p2_.addDraw();

//             // Each players take 3 cards.
//             for(int i=0;i<3;i++){
//                 alice.push_back(this->p1_.getCard());
//                 bob.push_back(this->p2_.getCard()); 
//             }
//             if(alice.back().getValue()>bob.back().getValue()){
//                 draw_winner=true;
//                 this->p1_.addWin();
//                 this->p2_.addLoss(); 
//                 this->last_turn= this->getTurn(this->p1_.getName(),alice.back())+
//                         this->getTurn(this->p2_.getName(),bob.back())+
//                         this->p1_.getName() + " won.\n";
//                 this->summary+=this->last_turn;                
//                 while(alice.size()>0){
//                     this->p1_.cardsWon();
//                     alice.pop_back();
//                     bob.pop_back();
//                 }
//             }
//             else if(alice.back().getValue()<bob.back().getValue()){
//                 draw_winner=true;
//                 this->p2_.addWin();
//                 this->p1_.addLoss(); 
//                 this->last_turn= this->getTurn(this->p1_.getName(),alice.back())+
//                         this->getTurn(this->p2_.getName(),bob.back())+
//                         this->p2_.getName() + " won.\n";
//                 this->summary+=this->last_turn;                
//                 while(alice.size()>0){
//                     this->p2_.cardsWon();
//                     alice.pop_back();
//                     bob.pop_back();
//                 }
//             }
            
//         }
//         if(draw_winner==false){
//             this->p1_.addDraw();
//             this->p2_.addDraw();
//             while(alice.size()>0){
//                 this->p1_.cardsWon();
//                 this->p2_.cardsWon();
//                 alice.pop_back();
//                 bob.pop_back();
//             }
//         }
//     }