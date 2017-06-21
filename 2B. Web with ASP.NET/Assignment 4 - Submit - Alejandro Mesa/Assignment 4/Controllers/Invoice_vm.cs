using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace Assignment_4.Controllers
{
    public class Invoice_vm { }

    public class InvoiceBase
    {

        [Key]
        [Display(Name = "Invoice Number")]
        public int InvoiceId { get; set; }

        [Display(Name = "Billing Address")]
        public string BillingAddress { get; set; }

        [Display(Name = "Billing City")]
        public string BillingCity { get; set; }

        [Display(Name = "Billing Country")]
        public string BillingCountry { get; set; }

        [Display(Name = "Postal Code")]
        public string BillingPostalCode { get; set; }

        [Display(Name = "Billing State")]
        public string BillingState { get; set; }

        [Display(Name = "Customer ID")]
        public int CustomerId { get; set; }

        [Display(Name = "Invoice Date")]
        public DateTime InvoiceDate { get; set; }

        [Display(Name = "Invoice Total")]
        public decimal Total { get; set; }

    }

    public class InvoiceWithDetail : InvoiceBase {

        public string CustomerFirstName { get; set; }
        public string CustomerLastName { get; set; }
        public string CustomerCity { get; set; }
        public string CustomerState { get; set; }
        public string CustomerEmployeeFirstName { get; set; }
        public string CustomerEmployeeLastName { get; set; }

        public IEnumerable<InvoiceLineWithDetail> InvoiceLines { get; set; }

        
        public InvoiceWithDetail()
        {
            InvoiceLines = new List<InvoiceLineWithDetail>();
        }
        

    }

    public class InvoiceLineBase
    {
        public int InvoiceLineId { get; set; }

        [Display(Name = "Invoice Number")]
        public int InvoiceId { get; set; }
        
        public int TrackId { get; set; }
        public decimal UnitPrice { get; set; }
        public int Quantity { get; set; }

        /*
        public InvoiceLineBase()
        {

        }
        */
    }

    public class InvoiceLineWithDetail : InvoiceLineBase
    {
        //public InvoiceBase Invoice { get; set; }

        public string TrackName { get; set; }
        public string TrackAlbumArtistName { get; set; }
        public string TrackAlbumTitle { get; set; }
        public string TrackComposer { get; set; }
        public string TrackMediaTypeName { get; set; }

        /*
        public InvoiceLineWithDetail()
        {

        }
        */
    }


}