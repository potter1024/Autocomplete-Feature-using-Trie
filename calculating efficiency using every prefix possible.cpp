    vector<ld> re;
    for(ll h=0;h<20000;h++){
        for(ll hh=1;hh<v[h].size();hh++){
            clock_t startTime=clock();
            string s{v[h].begin(),v[h].begin()+hh};
            suggestions(s);
            ld x1=(double(clock()-startTime )/(double)CLOCKS_PER_SEC);
            startTime=clock();
            for(ll i=0;i<20000;i++){
                if(v[i].size()<s.size())
                    continue;
                ll count=0;
                for(ll j=0;j<s.size();j++){
                    if(v[i][j]==s[j]){
                        count++;
                    }
                }
                if(count==s.size());
            }
            ld x2=(double(clock()-startTime )/(double)CLOCKS_PER_SEC);
            re.pb(x2/x1);
        }
        if(h%1000==0){
            cout<<((ld)h/((ld)(20000)))*100<<"% completed"<<endl;
        }
    }
    ld x=0.0;
    for(ll i=0;i<re.size();i++)
        x+=re[i];
    cout<<x/(ld)(re.size())<<endl;
