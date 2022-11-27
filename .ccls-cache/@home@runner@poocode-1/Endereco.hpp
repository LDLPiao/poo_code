#ifndef __ENDERECO__H__
#define __ENDERECO__H__

#define USE_MAPS_API true
//mudar para false para não precisar de usar a biblioteca curl.h

#include <string>
#include <iostream>
#include <sstream>

#if USE_MAPS_API 
//#include <curl/curl.h> //sudo aptitude install libcurl4-openssl-dev
#include "curl-master/include/curl/curl.h"
#endif

std::string HTTP_Request(std::string url);

class Endereco
{
    private: std::string _rua; public: std::string getRua(){return _rua;} void setRua(std::string rua){_rua = rua;}
    private: std::string _bairro;public: std::string getBairro(){return _bairro;} void setBairro(std::string bairro){_bairro = bairro;}
    private:std::string _cidade;public: std::string getCidade(){return _cidade;} void setCidade(std::string cidade){_cidade = cidade;}
    private:std::string _estado;public: std::string getEstado(){return _estado;} void setEstado(std::string estado){_estado = estado;}
    private:std::string _pais;public: std::string getPais(){return _pais;} void setPais(std::string pais){_pais = pais;}
    private:std::string _CEP;public: std::string getCEP(){return _CEP;} void setCEP(std::string cep){_CEP = cep;}
    private:std::string _latitude;public: std::string getLatitude(){return _latitude;} void setLatitude(std::string lat){_latitude = lat;}
    private:std::string _longitude;public: std::string getLongitude(){return _longitude;} void setLongitude(std::string lng){_longitude = lng;}
    private:int _numero;public: int getNumero(){return _numero;} void setNumero(int numero){_numero = numero;}

    private: static std::string API_key; public: static void setAPI_key(std::string key){API_key = key;}

    public:

    //@brief Construtor da classe
    Endereco(std::string rua = "", int numero = 0, std::string bairro = "", std::string cidade = "", std::string estado = "", std::string pais = "", std::string cep = ""): _rua(rua), _numero(numero), _bairro(bairro), _cidade(cidade), _estado(estado), _pais(pais), _CEP(cep)
    {
      completar_infos();
    }

    #if USE_MAPS_API //@brief Função que preenche as informações em branco do endereço
    void completar_infos()
    {
        if(_rua.compare("") == 0 || _numero == 0) return; //A função precisa de no mínimo dois parâmetros para funcionar.

        std::string address = address_concat(_rua, _numero, _bairro, _cidade, _estado);
        //std::cout << address << std::endl;
        std::string json = HTTP_Request("https://maps.googleapis.com/maps/api/geocode/json?address=" + address +"&language=pt-BR&key=" + API_key);

        if (_latitude.compare("") == 0)
        {
            std::size_t found = json.find("lat");
            if (found!=std::string::npos)
            {
                _latitude = json.substr(found + 7, 11);
                //std::cout << "latitude : |" << _latitude << "|" << std::endl;
            }
        }
        
        if (_longitude.compare("") == 0)
        {
            std::size_t found = json.find("lng");
            if (found!=std::string::npos)
            {
                _longitude = json.substr(found + 7, 11);
                //std::cout << "longitude : |" << _longitude << "|" <<std::endl;
            }
        }

        if (_bairro.compare("") == 0)
        {
            std::size_t found = json.find("route");
            if (found!=std::string::npos)
            {
                std::size_t inicio = json.find("long_name", found);
                std::size_t termino = json.find(",", inicio);
                _bairro = json.substr(inicio + 14, (termino - (inicio + 14)) - 1);
                //std::cout << "bairro : |" << _bairro << "|" <<std::endl;
            }
        }

        if (_cidade.compare("") == 0)
        {
            std::size_t found = json.find("sublocality_level_1");
            if (found!=std::string::npos)
            {
                std::size_t inicio = json.find("long_name", found);
                std::size_t termino = json.find(",", inicio);
                _cidade = json.substr(inicio + 14, (termino - (inicio + 14)) - 1);
                //std::cout << "cidade : |" << _cidade << "|" <<std::endl;
            }
        }

        if (_estado.compare("") == 0)
        {
            std::size_t found = json.find("administrative_area_level_2");
            if (found!=std::string::npos)
            {
                std::size_t inicio = json.find("long_name", found);
                std::size_t termino = json.find(",", inicio);
                _estado = json.substr(inicio + 14, (termino - (inicio + 14)) - 1);
                //std::cout << "estado : |" << _estado << "|" <<std::endl;
            }
        }

        if (_pais.compare("") == 0)
        {
            std::size_t found = json.find("administrative_area_level_1");
            if (found!=std::string::npos)
            {
                std::size_t inicio = json.find("long_name", found);
                std::size_t termino = json.find(",", inicio);
                _pais = json.substr(inicio + 14, (termino - (inicio + 14)) - 1);
                //std::cout << "pais : |" << _pais << "|" <<std::endl;
            }
        }

        if (_CEP.compare("") == 0)
        {
            std::size_t found = json.find("country");
            if (found!=std::string::npos)
            {
                std::size_t inicio = json.find("long_name", found);
                std::size_t termino = json.find(",", inicio);
                _CEP = json.substr(inicio + 14, (termino - (inicio + 14)) - 1);
                //std::cout << "CEP : |" << _CEP << "|" <<std::endl;
            }
        }
    }

    int distancia_ate(Endereco ponto)//@brief retorna a distância entre doi Endereços em metros.
    {
        //'https://maps.googleapis.com/maps/api/distancematrix/json?origins=Washington%2C%20DC&destinations=New%20York%20City%2C%20NY&units=imperial&key=YOUR_API_KEY'
        if(_rua.compare("") == 0 || _numero == 0) return 0;
        if(ponto.getRua().compare("") == 0 || ponto.getNumero() == 0) return 0;

        std::string address1 = address_concat(_rua, _numero, _bairro, _cidade, _estado);
        std::string address2 = address_concat(ponto.getRua(), ponto.getNumero(), ponto.getBairro(), ponto.getCidade(), ponto.getEstado());
        //std::cout << "https://maps.googleapis.com/maps/api/distancematrix/json?origins=" + address1 + "&destinations=" + address2 + "&units=metric&key=" + API_key << std::endl;
        std::string json = HTTP_Request("https://maps.googleapis.com/maps/api/distancematrix/json?origins=" + address1 + "&destinations=" + address2 + "&units=metric&key=" + API_key);
        //std::cout << json << std::endl;

        std::size_t found = json.find("distance");
        if (found!=std::string::npos)
        {
            std::size_t inicio = json.find("value", found);
            std::size_t termino = json.find("}", inicio);
            int dist = std::stoi(json.substr(inicio + 9, (termino - (inicio + 9)) - 16));
            //std::cout << "distância : |" << dist << "|" <<std::endl;
            return dist;
        }
        return 0;
    }

    #endif

    void operator=(Endereco e)
    {
      _rua = e.getRua();
      _numero = e.getNumero();
      _bairro = e.getBairro();
      _cidade = e.getCidade();
      _estado = e.getEstado();
      _pais = e.getPais();
      _CEP = e.getCEP();
      _latitude = e.getLatitude();
      _longitude = e.getLongitude();
    }

    std::string print()
    {
      stringstream endereco;
      endereco << _rua << ", " << _numero;
      return endereco.str();
    }

    std::string address_concat(std::string rua, int numero, std::string bairro, std::string cidade, std::string estado)
    {
        std::string address = remove_space(rua);
        address += ",%20" + std::to_string(numero);

        if(bairro.compare("") != 0) address += "%20-%20" + remove_space(bairro);
        if(cidade.compare("") != 0) address += ",%20" + remove_space(cidade);
        if(estado.compare("") != 0) address += "%20-%20" + remove_space(estado);

        return address;
    }

    std::string remove_space(std::string str)
    {
        std::string out;

        for (int i = 0; i < str.length(); ++i)
        {
            if (str[i] == ' ') out.append("%20");
                else out.push_back(str[i]);
        }

        return out;
    }


};

std::string Endereco::API_key = "";

#if USE_MAPS_API

static size_t WriteCallback(char *contents, size_t size, size_t nmemb, char *buffer_in)
{
    ((std::string*)buffer_in)->append((char*)contents, size * nmemb);
    //std::cout << *buffer_in << std::endl;
    return size * nmemb;
}
std::string HTTP_Request(std::string url)
{
    CURL *curl;
    CURLcode res;
    std::string readBuffer;
    curl = curl_easy_init();
    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str()); 
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback); 
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        return readBuffer;
    }
    return "";
}

#endif
#endif

