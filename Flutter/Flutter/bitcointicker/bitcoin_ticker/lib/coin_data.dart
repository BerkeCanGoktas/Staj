import 'dart:convert';

import 'package:http/http.dart' as http;

const List<String> currenciesList = [
  'AUD',
  'BRL',
  'CAD',
  'CNY',
  'EUR',
  'GBP',
  'HKD',
  'IDR',
  'ILS',
  'INR',
  'JPY',
  'MXN',
  'NOK',
  'NZD',
  'PLN',
  'RON',
  'RUB',
  'SEK',
  'SGD',
  'USD',
  'ZAR'
];

const List<String> cryptoList = [
  'BTC',
  'ETH',
  'LTC',
];

const URL = 'https://rest.coinapi.io/v1/exchangerate';

const APIKey = 'D75501E8-D028-48DE-81A3-20625CD42587';

class CoinData {
  String crypto = 'BTC';
  String currency = 'USD';

  CoinData({required this.crypto, required this.currency});

  String finalURL() {
    return '$URL/$crypto/$currency?apikey=$APIKey';
  }

  Future<double?> getRate() async{
      http.Response response = await http.get(Uri.parse(finalURL()));
      if (response.statusCode == 200) {
      var decodedData = jsonDecode(response.body);
      var lastPrice = decodedData['rate'];
      return lastPrice;
    } else {
      print(response.statusCode);
    }
  }
}
