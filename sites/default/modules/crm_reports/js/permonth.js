;
function crm_reports_show_permonth() {
  var data = Drupal.settings.crm_reports;
  jQuery('.permonth').highcharts({
    chart: {
      type: 'column'
    },
    title: {
      text: 'Monthly data'
    },
    subtitle: {
      text: 'Source: mkashu.bget.ru'
    },
    xAxis: {
      categories: [
        'Jan',
        'Feb',
        'Mar',
        'Apr',
        'May',
        'Jun',
        'Jul',
        'Aug',
        'Sep',
        'Oct',
        'Nov',
        'Dec',
        'TOTAL'
      ]
    },
    yAxis: {
      min: 0,
      title: {
        text: 'Count'
      }
    },
    tooltip: {
      headerFormat: '<span style="font-size:10px">{point.key}</span><table>',
      pointFormat: '<tr><td style="color:{series.color};padding:0">{series.name}: </td>' +
          '<td style="padding:0"><b>{point.y:.1f}</b></td></tr>',
      footerFormat: '</table>',
      shared: true,
      useHTML: true
    },
    plotOptions: {
      column: {
        groupPadding: 0.1,
        pointPadding: 0.1,
        borderWidth: 0
      }
    },
    spacing: [0, 0, 0, 0],
    series: data
  });
}