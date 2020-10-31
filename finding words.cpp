void recurse(char last_letter,string last_word,TrieNode *node){
    TrieNode *current=node;
    auto it=(current->children).begin();
    if(current->endofword==true);
        cout<<last_word+last_letter<<endl;
    while(it!=(current->children).end()){
        recurse(it->first,last_word+last_letter,it->second);
        it++;
    }
}
